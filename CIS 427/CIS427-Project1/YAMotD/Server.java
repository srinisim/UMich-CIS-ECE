/*
 * Server.java
 * Srinivas Simhan
 * CIS 427 - Prof. J.P. Baugh
 * Fall 2018 - Project 1
*/

import java.io.*;
import java.net.*;
import java.util.*;


public class Server
{

	public static final int SERVER_PORT = 4359;

	public static String MOTD = "Default Message Of The Day";
//	public static String StoredMessage;
	public static ArrayList<String> MOTDs = new ArrayList<String>(); // a list of the MOTDs

	public static OutputStream outFile;

	public static PrintStream os;
	public static BufferedReader is;

	public static String LoggedInUser; // keeps track of which user is logged in.
	public static boolean shutdown = false; // when true, the server shuts down

	// main method.
	public static void main(String args[]) throws IOException {
		System.out.println("**Server Active**");

		ReadMOTDs();

		ServerSocket myServerice = null;
		String line;


		Socket serviceSocket = null;

		// Try to open a server socket
		try
		{
			myServerice = new ServerSocket(SERVER_PORT);
		}
		catch (IOException e) {
			System.out.println(e);
		}

		// Create a socket object from the ServerSocket to listen and accept
		// connections.
		// Open input and output streams

		while (!shutdown)
		{
			System.out.println(" :] ");
			try
			{
				serviceSocket = myServerice.accept();
				is = new BufferedReader(new InputStreamReader(
						serviceSocket.getInputStream()));
				os = new PrintStream(serviceSocket.getOutputStream());

				// As long as we receive data, echo that data back to the
				// client.
				while (!shutdown && (line = is.readLine()) != null)
				{
					System.out.println("C: " + line); // Echoes received text in the server console

					RespondToMessage(line);

				}
				LogoutUser(LoggedInUser); // Logs the user out if they disconnect
				// close input and output stream and socket
				is.close();
				os.close();
				serviceSocket.close();
			}
			catch (IOException e)
			{
				System.out.println(e);
			}
		}
	  }

	// Reads in all of the MOTDs from a file and saves them into the MOTDs ArrayList
	private static void ReadMOTDs() throws IOException
	{
		InputStream inFile = new FileInputStream("messages.txt");
		BufferedReader reader = new BufferedReader(new InputStreamReader(inFile));
		String temp;

		while ((temp = reader.readLine())!= null)
			MOTDs.add(temp);

		inFile.close();
		reader.close();
	}

	// Helper function for sending messages to the client.
	public static void SendToClient(String message)
	{
		os.println(message + "\n[END]");
	}


	// Sends a MOTD to the client.
	private static void MSGGET()
	{
		SendToClient("200 OK\n" + MOTDs.get(new Random().nextInt(MOTDs.size())).toString());
	}

	// Logs out a user who wants to quit.
	private static void QUIT()
	{
		LogoutUser(LoggedInUser);
		SendToClient("200 OK");
	}

	// Attempts to login a user using the given username and password.
	private static void LOGIN(String line)
	{
		if (LoggedInUser != null)
		{
			SendToClient("User Already Logged In.");
		}
		else if (AttemptLogin(line))
		{
			SendToClient("S: 200 OK");
		}
		else
		{
			SendToClient("410 Wrong UserID or Password");
		}
	}

	// Logs out the currently logged in user.
	private static void LOGOUT()
	{
		LogoutUser(LoggedInUser);
		SendToClient("S: 200 OK");
	}

	// Stores a MOTD into messages.txt if a user is logged in.
	private static void MSGSTORE() throws IOException
	{
		if (LoggedInUser != null)
		{
			SendToClient("S: 200 OK");
			StoreMessage(is.readLine());
		}
		else
			SendToClient("401 You are not currently logged in, login first.");
	}

	// Tells the user to shutdown if user "root" is logged in.
	private static void SHUTDOWN()
	{
		System.out.println("shutdown received");
		if (LoggedInUser != null && LoggedInUser.equals("root"))
		{
			SendToClient("200 OK");
			shutdown = true;
		}
		else
			SendToClient("402 User not allowed to execute this command.");
	}


	//This method works out which message has been received, and decides what to do with it.
	private static void RespondToMessage(String message) throws IOException
	{
		String response;

		if (message.equals("MSGGET"))
		{
			MSGGET();
		}
		else if (message.equals("QUIT"))
		{
			QUIT();
		}
		else if (message.contains("LOGIN"))
		{
			LOGIN(message);
		}
		else if (message.equals("LOGOUT"))
		{
			LOGOUT();
		}
		else if (message.equals("MSGSTORE"))
		{
			MSGSTORE();
		}
		else if (message.equals("SHUTDOWN"))
		{
			SHUTDOWN();
		}
		else
		{
			SendToClient("Echo: " + message);
		}
	}

	// Attempts to login when issued a "LOGIN username password" command
	private static boolean AttemptLogin(String userInfo)
	{
		String username = "";
		String password = "";

		userInfo = userInfo.substring(6, userInfo.length());
		username = userInfo.substring(0,userInfo.indexOf(' '));
		password = userInfo.substring(userInfo.indexOf(' ')+1,userInfo.length());

		//System.out.println(" username: " + username);
		//System.out.println(" password: " + password);

		if (IsLoginSuccessful(username, password))
		{
			LoginUser(username);
			return true;
		}
		else
			return false;
	}

	//Returns true if the username&password combination results in a successful login.
	private static boolean IsLoginSuccessful(String username, String password)
	{
		switch (username)
		{
			case "root":
				if (password.equals("root01"))
					return true;
			case "john":
				if (password.equals("john01"))
					return true;
			case "david":
				if (password.equals("david01"))
					return true;
			case "mary":
				if (password.equals("mary01"))
					return true;
		}
		return false;
	}

	//Logs in the specified user.
	private static void LoginUser(String username)
	{
		LoggedInUser = username;
	}

	//Logs out the specified user.
	private static void LogoutUser(String username)
	{
		LoggedInUser = null;
	}

	//Stores a message into the MOTD file.
	private static void StoreMessage(String message)
	{
		System.out.println("Storing: " + message);

		try{
            FileWriter fstream = new FileWriter("messages.txt",true);
            BufferedWriter fbw = new BufferedWriter(fstream);
            fbw.newLine();
            fbw.write(message);
            fbw.close();
            MOTDs.add(message);
        }catch (Exception e) {
            System.out.println("Message Storing Error: " + e.getMessage());
        }
	}
}

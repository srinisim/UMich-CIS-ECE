 /*
  * Client.java
  * Srinivas Simhan
  * CIS 427 - Prof. J.P. Baugh
  * Fall 2018 - Project 1
 */

import java.io.*;
import java.net.*;

public class Client
{
    public static final int SERVER_PORT = 4359;
    public static final String SERVER_ADDRESS_HARDCODE = "localhost";
    public static void main(String[] args)
    {
      System.out.println("**Client Active**");
    	Socket clientSocket = null;
    	PrintStream os = null;
    	BufferedReader is = null;
    	String userInput = null;
    	String serverInput = null;
    	BufferedReader stdInput = null;
    	boolean quit = false;

    	//Check the number of command line parameters
    	if (args.length < 1)
    	{
    	    System.out.println("Usage: client <Server IP Address>");
    	    System.exit(1);
    	}

    	// Try to open a socket on SERVER_PORT
    	// Try to open input and output streams
    	try
    	{
    //		clientSocket = new Socket(SERVER_ADDRESS_HARDCODE, SERVER_PORT); // for debugging in eclipse
    	    clientSocket = new Socket(args[0], SERVER_PORT); // for running through SSH
    	    os = new PrintStream(clientSocket.getOutputStream());
    	    is = new BufferedReader (
    		new InputStreamReader(clientSocket.getInputStream()));
    	    stdInput = new BufferedReader(new InputStreamReader(System.in));
    	}
    	catch (UnknownHostException e)
    	{
    	    System.err.println("Don't know about host: hostname");
    	}
    	catch (IOException e)
    	{
    	    System.err.println("Couldn't get I/O for the connection to: hostname");
    	}

    	// If everything has been initialized then we want to write some data
    	// to the socket we have opened a connection to on port 3100

    	if (clientSocket != null && os != null && is != null)
    	{
  	    try
  	    {
  //	    	while ((userInput = stdInput.readLine())!= null)
  //	    	{
  //	    		os.println(userInput);
  //	    		serverInput = is.readLine();
  //	    		System.out.println("From Server:");
  //	    		System.out.println(serverInput);
  //	    	}
  	    	System.out.print("C: ");
  	    	while (!quit && (userInput = stdInput.readLine())!= null)
  	    	{
  	    		os.println(userInput);

  	    		System.out.print("S:");
  	    		while ( !quit && !(serverInput = is.readLine()).equals("[END]"))
  		    	{
  		    		System.out.println(" " + serverInput);

  		    		// If the server has acknowledged a QUIT command
  		    		if (userInput.equals("QUIT") && serverInput.equals("200 OK"))
  		    		{
  		    			System.out.println("Quitting");
  		    			quit = true;
  		    			break;
  		    		}

  		    		// If the server has acknowledged a MSGSTORE command
  		    		else if (userInput.equals("MSGSTORE") && serverInput.equals("200 OK"))
  		    		{
  		    			//System.out.print(" Input Message: ");
  		    			userInput = stdInput.readLine();
  		    			os.println(userInput);
  		    			System.out.println("  " + serverInput);
  		    		}

  		    		// If the server has acknowledged a SHUTDOWN command
  		    		else if (userInput.equals("SHUTDOWN") && serverInput.equals("200 OK"))
  		    		{
  		    			System.out.println("Quitting; Server Shutdown");
  		    			quit = true;
  		    			break;
  		    		}

  		    	}

  	    		if (!quit) System.out.print("C: ");
  	    	}

    		  // close the input and output stream
  		    // close the socket

  		    os.close();
  		    is.close();
  	      clientSocket.close();
  	    }
  	    catch (IOException e)
	    {
		      System.err.println("IOException:  " + e);
	    }
	   }
   }
}

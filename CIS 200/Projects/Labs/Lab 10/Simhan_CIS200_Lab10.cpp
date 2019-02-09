#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct clientData
{
	int accountNumber;
	char lastName[15];
	char firstName[10];
	float balance;
};

void printClientData(clientData c)
{
	cout << "Client data for account number: " << c.accountNumber << endl;
	cout << "\tLast name: " << c.lastName << endl;
	cout << "\tFirst name: " << c.firstName << endl;
	cout << "\tBalance: " << c.balance << endl << endl;
}

void createFile()
{
	ofstream outCredit("credit.dat", ios::out);
	clientData blankClient = { 0,"","",0.0 };

	for (int i = 0; i < 100; i++)
	{
		outCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(clientData));
	}
}

void writeFile()
{
	ofstream outCredit1("credit.dat", ios::ate); // access anywhere
	int userAccountNumber = -1;
	while (userAccountNumber != 0) {
		cout << "Enter an account number (1-100, 0 to stop): ";
		cin >> userAccountNumber;
		if (userAccountNumber <= 100 && userAccountNumber >= 1) {
			clientData client;
			client.accountNumber = userAccountNumber;
			cout << "Enter last name: ";
			char lastname[15];
			cin >> lastname;
			memcpy(client.lastName, lastname, 15 * sizeof(char));
			cout << "Enter first name: ";
			char firstname[10];
			cin >> firstname;
			memcpy(client.firstName, firstname, 10 * sizeof(char));
			cout << "Enter balance: ";
			float balance;
			cin >> balance;
			client.balance = balance;

			outCredit1.seekp((client.accountNumber - 1) * sizeof(clientData));
			outCredit1.write(reinterpret_cast<const char*>(&client), sizeof(clientData));
		}
	}
}

void readFile(ifstream& inCredit)
{
	clientData client;
	int userAccountNumber = -1;
	while (userAccountNumber != 0) {
		cout << "Enter account number (1-100, 0 to stop): ";
		cin >> userAccountNumber;
		if (userAccountNumber >= 1 && userAccountNumber <= 100)
		{
			inCredit.seekg((userAccountNumber - 1) * sizeof(clientData));
			inCredit.read(reinterpret_cast<char*>(&client), sizeof(clientData));
			printClientData(client);
		}
	}
}

void printFile(ifstream& inCredit)
{
	clientData client;
	inCredit.read(reinterpret_cast<char*>(&client), sizeof(clientData));
	while (inCredit && !inCredit.eof())
	{
		if (client.accountNumber != 0)
		{
			printClientData(client);
		}
		inCredit.read(reinterpret_cast<char *>(&client), sizeof(clientData));
	}
}

int main()
{
	createFile();
	writeFile();
	ifstream inCredit("credit.dat", ios::in);
	readFile(inCredit);
	printFile(inCredit);
	return 0;
}
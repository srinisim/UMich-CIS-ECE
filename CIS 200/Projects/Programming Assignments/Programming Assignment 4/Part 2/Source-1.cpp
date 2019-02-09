#include "classes.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	Account *accountPtrs[100];
	int acctNum;

	for (int i = 0; i < 100; i++)
	{
		accountPtrs[i] = nullptr;
	}

	for (int i = 0; i < 5; i++)
	{
		Checking* c = new Checking(Checking::getNextAccountNumber(), 0);
		c->setBalance(1000 + (10 * (c->getAcct())));
		accountPtrs[i] = c;
	}

	for (int i = 5; i < 10; i++)
	{
		Saving* s = new Saving(Saving::getNextAccountNumber(), 0, .03);
		s->setBalance(1000 + (10 * (s->getAcct())));
		accountPtrs[i] = s;
	}

	char action;

	//action
	while (action != 'q')
	{
		cout << endl << endl << "How to use:\n 'a': Add Account\n 'r': Remove Account\n 'g': Get Account\n 'b': Set Balance\n 'i': Set Interest\n 'd': Display Account # & Balance\n 'c': Display Interest. Wait to enter in the # of years you wish to calculate for\n 'q': Quit Processing this account\n" << endl;
		cin >> action;

		switch (action)
		{
		case 'A': case 'a': //Add Account
			char type;
			
			cout << "Enter the account number you wish to add: " << endl;
			cin >> acctNum;
			cout << "Is this a checking account or a savings account? Enter c or s." << endl;
			cin >> type;
			
			if (type == 'c')
			{
				accountPtrs[acctNum] = new Checking(acctNum, 0.0);
				accountPtrs[acctNum]->setBalance((1000 + 10 * acctNum));
				cout << "Checking account " << acctNum << " has been added." << endl;
			}
			else if (type == 's')
			{
				accountPtrs[acctNum] = new Saving(acctNum, 0.0, 0.03);
				accountPtrs[acctNum]->setBalance((100 + 10 * acctNum));
				cout << "Saving account " << acctNum << " has been added." << endl;
			}
			else
			{
				cout << "Invalid Input. Please try again!" << endl;
			}
			break;

		case 'R': case 'r': //Remove Account
			cout << "Enter the account number you wish to remove: " << endl;
			cin >> acctNum;
			accountPtrs[acctNum] = nullptr;
			cout << "Account number " << acctNum << " has been removed." << endl;
			break;

		case 'G': case 'g': //Get Account
			cout << "Enter the account number you wish to view the information of: " << endl;
			cin >> acctNum;
			cout << accountPtrs[acctNum]->toString();

			break;

		case 'B': case 'b': //Set Balance
			cout << "Enter the account number you wish to change the balance of: " << endl;
			cin >> acctNum;
			cout << "Is this a checking account or a savings account? Enter c or s." << endl;
			cin >> type;

			if (type == 'c')
			{
				double bal;

				cout << "What would you like to change the balance to?" << endl;
				cin >> bal;
				accountPtrs[acctNum]->setBalance(bal);
				cout << "Checking account balance is now: $" << bal << endl;
			}
			else if (type == 's')
			{
				double bal;

				cout << "What would you like to change the balance to?" << endl;
				cin >> bal;
				accountPtrs[acctNum]->setBalance(bal);
				cout << "Saving account balance is now: $" << bal << endl;
			}
			else
			{
				cout << "Invalid Input. Please try again!" << endl;
			}
			break;

		case 'I': case 'i': //Set Interest
			cout << "Enter the account number you wish to change the interest rate of: " << endl;
			cin >> acctNum;
			cout << "Is this a savings account? Enter y if it is." << endl;
			cin >> type;

			if (type == 'y' || type == 'Y')
			{
				double rate;

				cout << "What would you like to change the interest rate to?" << endl;
				cin >> rate;
				cout << "Checking account interest is now: " << rate << endl;
			}
			else
			{
				cout << "It is not a savings account. Please try again!" << endl;
			}
			break;
			
		case 'D': case 'd': //Display Using the toString function
			accountPtrs[acctNum]->toString();
			break;

		case 'C': case 'c': //Waits for user to enter the # of years then displays the interest
		// need to finish
			try
			{
				// something that uses computeIntr()
				
			}
			catch (Account::negBal)
			{
				cout << "Attempt to compute interest using a negative balance";
			}
			break;

		case 'Q': case 'q': //Quit processing this account
			cout << "Thank you for processing this account, looking forward to seeing you soon!" << endl;
			break;

		default:
			cout << "Incorrect Input, please try again" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
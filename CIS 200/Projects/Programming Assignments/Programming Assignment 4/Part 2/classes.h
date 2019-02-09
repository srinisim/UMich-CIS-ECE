#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

//ACCOUNT CLASS
class Account 
{
private:
	long acctNum;
	double balance;

public:
	//GET & SET Account
	void setAcct(long acct)
	{
		acctNum = acct;
	}; 
	
	long getAcct()
	{
		return acctNum;
	};

	//GET & SET Balance
	void setBalance(double bal)
	{
		balance = bal;
	};
	
	double getBalance()
	{
		return balance;
	};

	//Constructor
	Account::Account(long acct, double bal)
	{
		acctNum = acct;
		balance = bal;
	};

	//Return AcctNum & balance
	string virtual toString()
	{
		cout << "Account Num: " << acctNum << endl;
		cout << "\tBalance: $"<< balance << endl;
		
		return 0;
	};

	class negBal : exception {};

	//Compute Interest
	double virtual computeIntr(int years) 
	{
		return NULL;
	}
};

//CHECKING CLASS
class Checking : public Account 
{
private:
	int minIntrBalance;
	int intRate;
	static int nextAccountNumber;
public:
	//SET & GET MIN INTR BALANCE
	void setMinIntrBalance(int lowestBalance)
	{
		if (lowestBalance < 0)
		{
			minIntrBalance = lowestBalance;
		}
		else
		{
			cout << "Can't set minimum balance to a negative number." << endl;
		}
	}; 
	
	int getMinIntrBalance()
	{
		return minIntrBalance;
	};
	
	//SET & GET RATE
	void setRate(int rate)
	{
		if (rate < 0)
		{
			intRate = rate;
		}
		else
		{
			cout << "Can't set rate to a negative." << endl;
		}
	};

	int getRate()
	{
		return intRate;
	};

	//Compute Interest
	double computeIntr(int years)
	{
		if (getBalance() >= minIntrBalance)
		{
			return (getRate() * getBalance() * years);
		}
		else
		{
			throw negBal();
		}
	};

	//Constructor
	Checking::Checking(long acct, double bal):Account(acct, bal)
	{
		nextAccountNumber = acct + 1;
	};

	static int getNextAccountNumber ()
	{
		return nextAccountNumber;
	}

	//Return Checking AcctNum & Checking balance
	string toString()
	{
		cout << "Account Num: " << getAcct() << endl;
		cout << "\tChecking Balance: $" << getBalance() << endl;
		return 0;
	};
	
};

int Checking::nextAccountNumber = 100;

//SAVING CLASS
class Saving : public Account
{
private:
	double intRate;
	static int nextAccountNumber;

public:
	//SET & GET RATE
	void setRate(double rate)
	{
		if (intRate <= 0)
		{
			intRate = rate;
		}
		else
		{
			cout << "Interest Rate is negative, and therefore is not accepted. Try Again" << endl;
		}
	};

	double getRate()
	{
		return intRate;
	};

	//Compute Interest
	double computeIntr(int years)
	{
		return ((pow(1 + getRate(), years) * getBalance()) - getBalance());
	};

	Saving::Saving(long acct, double bal, double rate):Account(acct, bal)
	{
		nextAccountNumber = acct + 1;
		setAcct(acct);
		setBalance(bal);
		setRate(rate);
	};

	static int getNextAccountNumber()
	{
		return nextAccountNumber;
	}

	//Return Saving AcctNum & Saving balance
	string toString()
	{
		cout << "Account Num: " << getAcct() << endl;
		cout << "\tSaving Balance: $" << getBalance() << endl;
		cout << "\tSaving Rate: " << getRate() << endl;
		return 0;
	};
};
int Saving::nextAccountNumber = 200;

#endif
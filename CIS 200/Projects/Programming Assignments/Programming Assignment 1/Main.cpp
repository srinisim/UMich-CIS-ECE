#include <iostream>
#include <string>
using namespace std;

class myString // Standard way of defining the class
{
private:
	int length = 0;

public:
	// Constructor
	myString();
	myString(string);
	char str[25] = { '\0' };

	// Functions
	int size();
	void addStart(myString);
	void addEnd(myString);
	myString partString(int startPos, int length);
	void replPartString(myString, int startPos);
	void replWholeString(myString);
	bool compareString(myString);
	void initString();
	void setString(string);
	string getString();
	void printString();

};

myString::myString()
{

}

myString::myString(string initial)
{
	for (int i = 0; i < initial.size(); i++)
	{
		str[i] = initial.at(i);
	}
	length = initial.size();
}

int myString::size()
{
	return length;
}

void myString::addStart(myString prefix)
{
	if (prefix.size() + size() > 25)
	{
		throw "Maximum size exceeded";
	}

	char oldStr[25];
	for (int i = 0; i < length; i++)
	{
		oldStr[i] = str[i];
	}

	for (int i = 0; i < prefix.size(); i++)
	{
		str[i] = prefix.str[i];
	}
	for (int i = 0; i < length; i++)
	{
		str[i + prefix.size()] = oldStr[i];
	}
	length = prefix.length + length;
}

void myString::addEnd(myString postfix)
{
	if (postfix.size() + size() > 25)
	{
		throw "Maximum size exceeded";
	}

	for (int i = 0; i < postfix.size(); i++)
	{
		str[i + size()] = postfix.str[i];
	}

	length = size() + postfix.size();
}

myString myString::partString(int startPos, int partLength)
{
	if (startPos < 0)
	{
		throw "startPos must be >= 0";
	}

	if (startPos > size())
	{
		throw "startPos must not exceed size";
	}

	myString part;

	if (startPos == size())
	{
		return part;
	}

	for (int i = startPos; i < startPos + partLength; i++)
	{
		part.str[i - startPos] = str[i];
	}
	part.length = partLength;
	return part;
}

void myString::replPartString(myString part, int startPos)
{
	if (startPos + part.size() > 25)
	{
		throw "Maximum size exceeded";
	}

	for (int i = 0; i < part.size(); i++)
	{
		str[i + startPos] = part.str[i];
	}

	if (startPos + part.size() > length)
	{
		length = startPos + part.size();
	}
}

void myString::replWholeString(myString s)
{
	for (int i = 0; i < s.length; i++)
	{
		str[i] = s.str[i];
	}
	length = s.length;
}

bool myString::compareString(myString s)
{
	if (s.size() != size())
	{
		return false;
	}
	for (int i = 0; i < size(); i++)
	{
		if (str[i] != s.str[i])
		{
			return false;
		}
	}
	return true;
}

void myString::initString()
{
	for (int i = 0; i < 25; i++)
	{
		str[i] = '\0';
	}
	length = 0;
}

void myString::setString(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		str[i] = s.at(i);
	}
	length = s.size();
}

string myString::getString()
{
	string s;
	for (int i = 0; i < length; i++)
	{
		s.push_back(str[i]);
	}
	return s;
}

void myString::printString()
{
	for (int i = 0; i < length; i++)
	{
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	myString m("herp");
	cout << m.getString();
	return 0;
}

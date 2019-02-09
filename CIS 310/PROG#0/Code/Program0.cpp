/*
Assignment Name: Program 0
Programmer: Srinivas Simhan
Class: CIS-310 (Yoon) - Winter 2018
Program Description: This program converts decimal numbers 1->255 into Binary, Hexdecimalidecimal, and BCD numbers. Then it outputs them to a file called "output.txt"
Last Modified: 01/17/2018
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

string HexDictionary(string Half)	//Set Standard Dictionary Created
{
	if (Half == "0000")
	{
		return "0";
	}
	if (Half == "0001")
	{
		return "1";
	}
	if (Half == "0010")
	{
		return "2";
	}
	if (Half == "0011")
	{
		return "3";
	}
	if (Half == "0100")
	{
		return "4";
	}
	if (Half == "0101")
	{
		return "5";
	}
	if (Half == "0110")
	{
		return "6";
	}
	if (Half == "0111")
	{
		return "7";
	}
	if (Half == "1000")
	{
		return "8";
	}
	if (Half == "1001")
	{
		return "9";
	}
	if (Half == "1010")
	{
		return "A";
	}
	if (Half == "1011")
	{
		return "B";
	}
	if (Half == "1100")
	{
		return "C";
	}
	if (Half == "1101")
	{
		return "D";
	}
	if (Half == "1110")
	{
		return "E";
	}
	if (Half == "1111")
	{
		return "F";
	}
}
string DecToBin(int decNum)				//Works with all functions.
{
	string binNum = "0000 0000";		//Setting the string default
	for (int i = 8; i >= 0; i--)
	{
		if (i == 4)
		{
		}								//If statement case for NULL ' '.
		else if (decNum % 2 == 1)
		{
			binNum[i] = '1';
		}
		if (i != 4)
		{
			decNum = (decNum - decNum % 2) / 2;
		}
	}
	return binNum;
}
string DecToHex(int decNum)
{
	string Binary = DecToBin(decNum);
	string SecHalf = Binary.substr(5, 4);
	string FirstHalf = Binary.substr(0, 4);
	string HexNum = HexDictionary(FirstHalf) + HexDictionary(SecHalf);
	return HexNum;
}
string DecToBCD(int decNum)
{
	string BCD;
	string temp1, temp2, temp3;
	temp1 = DecToBin((decNum % 10)).substr(5, 4);
	decNum -= decNum % 10;
	temp2 = DecToBin((decNum % 100) / 10).substr(5, 4);
	decNum -= decNum % 100;
	temp3 = DecToBin((decNum % 1000) / 100).substr(5, 4);
	BCD = temp3 + " " + temp2 + " " + temp1;
	return BCD;
}
int main()
{
	ofstream output;
	output.open("output.txt");
	output << "DECIMAL" << setw(10) << "BINARY" << setw(19) << "HEXDECIMAL" << setw(12) << "BCD" << endl;
	for (int i = 0; i <= 255; i++)
	{
		{
			if (i <= 9)
			{
				output << i << setw(19) << DecToBin(i) << setw(8) << DecToHex(i) << setw(31) << DecToBCD(i) << endl;
			}
			else if (i <= 99)
			{
				output << i << setw(18) << DecToBin(i) << setw(8) << DecToHex(i) << setw(31) << DecToBCD(i) << endl;
			}
			else
			{
				output << i << setw(17) << DecToBin(i) << setw(8) << DecToHex(i) << setw(31) << DecToBCD(i) << endl;
			}
		}
	}
	return 0;
}
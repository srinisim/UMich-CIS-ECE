//	Author: Srinivas Simhan
//	Program: CIS 310 - Program 4
//	Due: 4/4/18

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int hex2Dec(char hex)
{
	if (hex == '0')
	{
		return 0;
	}
	if (hex == '1')
	{
		return 1;
	}
	if (hex == '2')
	{
		return 2;
	}
	if (hex == '3')
	{
		return 3;
	}
	if (hex == '4')
	{
		return 4;
	}
	if (hex == '5')
	{
		return 5;
	}
	if (hex == '6')
	{
		return 6;
	}
	if (hex == '7')
	{
		return 7;
	}
	if (hex == '8')
	{
		return 8;
	}
	if (hex == '9')
	{
		return 9;
	}
	if (hex == 'A')
	{
		return 10;
	}
	if (hex == 'B')
	{
		return 11;
	}
	if (hex == 'C')
	{
		return 12;
	}
	if (hex == 'D')
	{
		return 13;
	}
	if (hex == 'E')
	{
		return 14;
	}
	if (hex == 'F')
	{
		return 15;
	}
}

char dec2Hex(int dec)
{
	if (dec == 0)
	{
		return '0';
	}
	if (dec == 1)
	{
		return '1';
	}
	if (dec == 2)
	{
		return '2';
	}
	if (dec == 3)
	{
		return '3';
	}
	if (dec == 4)
	{
		return '4';
	}
	if (dec == 5)
	{
		return '5';
	}
	if (dec == 6)
	{
		return '6';
	}
	if (dec == 7)
	{
		return '7';
	}
	if (dec == 8)
	{
		return '8';
	}
	if (dec == 9)
	{
		return '9';
	}
	if (dec == 10)
	{
		return 'A';
	}
	if (dec == 11)
	{
		return 'B';
	}
	if (dec == 12)
	{
		return 'C';
	}
	if (dec == 13)
	{
		return 'D';
	}
	if (dec == 14)
	{
		return 'E';
	}
	if (dec == 15)
	{
		return 'F';
	}
}

string adder(string op1, string op2)
{
	int total = 0;
	string ReturnString = "";
	int carry = 0;
	string reverse = "";
	int j = op2.length() - 1;
	for (int i = op1.length() - 1; i >= 0 || j >= 0; i--)
	{
		total = 0;
		if (i < 0 && j >= 0)
		{
			total = hex2Dec(op2[j]) + carry;
		}
		else if (i >= 0 && j < 0)
		{
			total = hex2Dec(op1[i]) + carry;
		}
		else
		{
			total = hex2Dec(op1[i]) + hex2Dec(op2[j]) + carry;
		}
		if (total > 31)
		{
			ReturnString += dec2Hex(total - 32);
			carry = 2;
		}
		else if (total > 15)
		{
			ReturnString += dec2Hex(total - 16);
			carry = 1;
		}
		else
		{
			ReturnString += dec2Hex(total);
			carry = 0;
		}
		j--;
	}
	ReturnString += dec2Hex(carry);
	for (int flip = ReturnString.size() - 1; flip >= 0; flip--)
	{
		reverse += ReturnString[flip];
	}
	if (reverse[0] == '0')
	{
		reverse = reverse.substr(1, reverse.size());
	}
	return reverse;
}

string subtractor(string op1, string op2)
{
	int total = 0;
	string ReturnString = "";
	int carry = 0;
	int pos1, pos2;
	string reverse = "";
	int j = op2.length() - 1;
	int i = op1.length() - 1;
	int k = 0;
	for (; i >= 0 && j >= 0; i--)
	{
		pos1 = hex2Dec(op1[i]);
		pos2 = hex2Dec(op2[j]);
		if (pos1 < pos2)
		{
			ReturnString += dec2Hex(pos1 - pos2 + 16);
			k = i - 1;
			if (k < 0)
			{
				ReturnString = "-1";
				return ReturnString;
			}
			while (op1[k] == '0')
			{
				k--;
			}
			if (k >= 0)
			{
				op1[k] = dec2Hex(hex2Dec(op1[k]) - 1);
				while (k < i)
				{
					k++;
					op1[k] = 'F';
				}
			}
		}
		else
		{
			ReturnString += dec2Hex(pos1 - pos2);
		}
		j--;
	}
	if (i > j)
	{
		for (; i >= 0; i--)
		{
			ReturnString += op1[i];
		}
	}
	else if (j>i)
	{
		for (; j >= 0; j--)
		{
			ReturnString += op2[j];
		}
		ReturnString += '-';
	}
	for (int flip = ReturnString.size() - 1; flip >= 0; flip--)
	{
		reverse += ReturnString[flip];
	}
	if (reverse[0] == '0')
	{
		reverse = reverse.substr(1, reverse.size());
	}
	return reverse;
}

string multiply(string op1, string op2)
{
	string changer;
	while (op2 != "")
	{
		op2 = subtractor(op2, "1");
		changer = adder(changer, op1);
	}
	return changer;
}

string divide(string op1, string op2)
{
	string changer;
	string devider;
	changer = op1;
	while (subtractor(changer, op2) != "-1")
	{
		changer = subtractor(changer, op2);
		devider = adder(devider, "1");
	}
	devider += " Remainder: ";
	devider += changer;
	return devider;
}

string powers(string op1, string op2)
{
	string changer = "1";
	string add;
	while (op2 != "")
	{
		op2 = subtractor(op2, "1");
		changer = multiply(changer, op1);
	}
	return changer;
}

int main()
{
	cout << "TEST DATA: " << endl << endl;

	ifstream input;
	ofstream output;
	string out;
	string full, operand1, operator1, operand2;
	input.open("input.txt");
	output.open("output.txt");
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> full;
			for (int i = 0; i < full.length(); i++)
			{
				if (full[i] == '+' || full[i] == '-' || full[i] == '/' || full[i] == '$' || full[i] == '*')
				{
					operator1 = full[i];
					operand1 = full.substr(0, i);
					operand2 = full.substr(i + 1, full.length());
					if (operand2[operand2.length() - 1] == '=')
					{
						operand2 = operand2.substr(0, operand2.length() - 1);
					}
				}
			}
			if (operator1 == "+")
			{
				out = adder(operand1, operand2);
			}
			if (operator1 == "-")
			{
				out = subtractor(operand1, operand2);
			}
			if (operator1 == "*")
			{
				out = multiply(operand1, operand2);
			}
			if (operator1 == "$")
			{
				out = powers(operand1, operand2);
			}
			if (operator1 == "/")
			{
				out = divide(operand1, operand2);
			}
			cout << full;
			output << full;
			cout << " ";
			output << " ";
			cout << out;
			output << out;
			cout << endl;
			output << endl;
		}
	}
	system("pause");
	return 0;
}
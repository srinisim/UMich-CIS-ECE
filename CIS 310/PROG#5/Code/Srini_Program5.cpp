/*
	Programmer: Srinivas Simhan
	Class: CIS 310 (Yoon) - Program 5
	Due: 4/27/18
*/

#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<iomanip>
using namespace std;

struct Table
{
	int address;
	string machine;
	string Op;
	string Op2;
	string instruct;
	string extras;
};

vector<string> spacePurge(vector<string>& original)
{
	int location = 0;
	string temp = "";
	vector<string> returnS;

	for (int i = 0; i < original.size(); i++)
	{
		temp = "";
		for (int j = 0; j < original[i].size(); j++)
		{
			if (j == 0 && original[i][j] == ' ')
			{
				temp += ' ';
			}
			else if (j != 0 && original[i][j] == ' ' && original[i][j - 1] != ' ')
			{
				temp += ' ';
			}
			else if (original[i][j] != ' ')
			{
				temp += original[i][j];
			}
		}
		returnS.push_back(temp);
	}
	return returnS;
}

vector<string> PassOne(vector<string> & original, vector<Table> & table, map<string, int>& symbol)
{
	int labelnum;
	string symbolV;
	int op1 = 0;
	int op2 = 0;
	stringstream stream;
	int memory = 0;
	string hexN = "";
	Table tempT;
	tempT.Op = "";
	tempT.Op2 = "";

	for (int i = 0; i < original[i].size(); i++)
	{
		if (original[i][0] != ' ')
		{
			symbolV = "";
			for (labelnum = 0; original[i][labelnum] != ' '; labelnum++)
			{
				symbolV += original[i][labelnum];
			}
			original[i].erase(original[i].find(symbolV), symbolV.size());
			symbol[symbolV] = memory;
		}
		symbolV = "";
		for (labelnum = 1; original[i][labelnum] != ' '; labelnum++)
		{
			symbolV += original[i][labelnum];
		}
		if (symbolV == "ORG")
		{
			labelnum += 2;
			hexN = "";
			for (; labelnum < original[i].size() && original[i][labelnum] != ' '; labelnum++)
			{
				hexN += original[i][labelnum];
			}
			stream << hexN;
			stream >> hex >> memory;
		}
		if (symbolV == "MOVE")
		{
			labelnum += 1;
			hexN = "";
			if (original[i][labelnum] == '#')
			{
				hexN = "";
				for (; labelnum < original[i].size() && original[i][labelnum] != ' ' && original[i][labelnum - 1] != ','; labelnum++)
				{
					if (original[i][labelnum] == ',')
					{
						hexN += original[i][labelnum];
						labelnum++;
					}
					hexN += original[i][labelnum];
				}
				tempT.Op = "";
				tempT.address = memory;
				tempT.extras = hexN;
				tempT.instruct = "MOVE";
				memory += 8;
				table.push_back(tempT);
			}
			else if (original[i][labelnum] == '$' || original[i][labelnum] == 'D')
			{
				hexN = "";
				for (; labelnum < original[i].size() && original[i][labelnum] != ' ' && original[i][labelnum - 1] != ','; labelnum++)
				{
					if (original[i][labelnum] == ',')
					{
						hexN += original[i][labelnum];
						labelnum++;
					}
					hexN += original[i][labelnum];
				}
				tempT.address = memory;
				tempT.extras = hexN;
				tempT.instruct = "MOVE";
				memory += 6;
				table.push_back(tempT);
			}
		}
		if (symbolV == "ADD")
		{
			hexN = "";
			labelnum++;
			for (; labelnum < original[i].size() && original[i][labelnum] != ' ' && original[i][labelnum - 1] != ','; labelnum++)
			{
				if (original[i][labelnum] == ',')
				{
					hexN += original[i][labelnum];
					labelnum++;
				}
				hexN += original[i][labelnum];
			}
			tempT.address = memory;
			tempT.extras = hexN;
			tempT.instruct = "ADD";
			memory += 6;
			table.push_back(tempT);
		}
		if (symbolV == "ADDI")
		{
			hexN = "";
			labelnum++;
			for (; labelnum < original[i].size() && original[i][labelnum] != ' ' && original[i][labelnum - 1] != ','; labelnum++)
			{
				if (original[i][labelnum] == ',')
				{
					hexN += original[i][labelnum];
					labelnum++;
				}
				hexN += original[i][labelnum];
			}
			tempT.address = memory;
			tempT.extras = hexN;
			tempT.instruct = "ADDI";
			memory += 8;
			table.push_back(tempT);
		}
		if (symbolV == "TRAP")
		{
			labelnum += 2;
			tempT.address = memory;
			tempT.extras = original[i][labelnum];
			tempT.Op = "";
			tempT.instruct = "TRAP";
			table.push_back(tempT);
			memory += 2;
		}
	}
	return original;
}

Table findOps(Table& table)
{
	table.Op = "";
	table.Op2 = "";
	int value = 0;
	int i = 0;
	stringstream stream;

	if (table.extras[0] == 'D')
	{
		i += 2;
	}

	if (table.extras[0] == '1' || table.extras[0] == '2' || table.extras[0] == '0')
	{
		return table;
	}

	if (table.extras[0] == '$')
	{
		i = 1;
		while (i < table.extras.size() && table.extras[i] != ',')
		{
			table.Op += table.extras[i];
			i++;
		}
	}

	if (table.extras[0] == '#')
	{
		i = 1;
		while (i < table.extras.length() && table.extras[i] != ',')
		{
			table.Op += table.extras[i];
			i++;
		}
		value = atoi(table.Op.c_str());
		stream << hex << value;
		table.Op = "";
		stream >> hex >> table.Op;
	}
	i += 2;

	if (table.extras[i] == '#')
	{
		i++;
		table.Op2 = table.extras.substr(i, table.extras.length());
		value = atoi(table.Op2.c_str());
		stream << hex << value;
		table.Op2 = "";
		stream >> hex >> table.Op2;
	}
	else if (table.extras[i] == '$')
	{
		i++;
		table.Op2 = table.extras.substr(i, table.extras.length());
	}

	return table;
}

bool PassTwo(vector<Table> & table)
{
	string temp = "";

	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].instruct == "ADD")
		{
			table[i].machine = "D079";
			findOps(table[i]);
		}
		else if (table[i].instruct == "ADDI")
		{
			table[i].machine = "0679";
			findOps(table[i]);
		}
		else if (table[i].instruct == "MOVE")
		{
			if (table[i].extras[0] == '$')
			{
				table[i].machine = "3039";
			}
			if (table[i].extras[0] == 'D')
			{
				table[i].machine = "33C0";
			}
			if (table[i].extras[0] == '#')
			{
				table[i].machine = "33FC";
			}
			findOps(table[i]);
		}
		else if (table[i].instruct == "TRAP")
		{
			if (table[i].extras == "0")
			{
				table[i].machine = "4E40";
			}
			if (table[i].extras == "1")
			{
				table[i].machine = "4E41";
			}
			if (table[i].extras == "2")
			{
				table[i].machine = "4E42";
			}
			temp = table[i].extras;
			table[i].extras = "";
			table[i].extras += "#";
			table[i].extras += temp;
		}
	}

	return true;
}

string comma(string op1, string op2)
{
	if (op1 != "" && op2 != "")
	{
		return ", ";
	}
	else
	{
		return "";
	}
}

void printTable(vector<Table> table, map<string, int> symbol)
{
	ofstream output;
	output.open("output.txt", ofstream::out | ofstream::app);
	cout << left;
	output << left;
	cout << endl;
	output << endl;
	cout << setw(10) << "Address" << setw(14) << "Machine Code" << setw(15) << "Operands" << setw(15) << "Instructions" << endl;
	output << setw(10) << "Address" << setw(14) << "Machine Code" << setw(15) << "Operands" << setw(15) << "Instructions" << endl;

	for (int i = 0; i < table.size(); i++)
	{
		cout << "00000";
		output << "00000";
		cout << hex << table[i].address;
		output << hex << table[i].address;
		cout << "  ";
		output << "  ";
		cout << setw(14) << table[i].machine << setw(15) << table[i].Op + comma(table[i].Op, table[i].Op2) + table[i].Op2 << setw(15) << table[i].instruct << setw(10) << table[i].extras << endl;
		output << setw(14) << table[i].machine << setw(15) << table[i].Op + comma(table[i].Op, table[i].Op2) + table[i].Op2 << setw(15) << table[i].instruct << setw(10) << table[i].extras << endl;
	}
	cout << endl;
	output << endl;
	cout << "Symbol Table" << endl;
	output << "Symbol Table" << endl;
	cout << setw(10) << "Label" << setw(10) << "Memory Address" << endl;
	output << setw(10) << "Label" << setw(10) << "Memory Address" << endl;
	for (map<string, int>::iterator it = symbol.begin(); it != symbol.end(); ++it)
	{
		cout << setw(10) << it->first;
		output << setw(10) << it->first;
		cout << "00000";
		output << "00000";
		cout << hex << it->second;
		output << hex << it->second;
		cout << endl;
		output << endl;
	}
	output.close();
}

int main()
{
	ofstream output;
	output.open("output.txt");
	vector<Table> table;
	string temp;
	map<string, int> symbol;
	ifstream input;
	string lines;
	int memory;
	vector<string> original;
	input.open("input.txt");
	while (!input.eof())
	{
		getline(input, lines);
		original.push_back(lines);
	}
	input.close();
	for (int i = 0; i < original.size(); i++)
	{
		cout << original[i] << endl;
		output << original[i] << endl;
	}
	int labelnum;
	original = spacePurge(original);
	original = PassOne(original, table, symbol);
	PassTwo(table);
	output.close();
	printTable(table, symbol);
	system("pause");
	return 0;
}
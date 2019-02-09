#include <iostream>
#include <string>
#include <cstdio>
#include <exception>
using namespace std;

class Date
{
public:
	int month;
	int day;
	int year;

	class MonthException : public exception {};
	class DayException : public exception {};
	class YearException : public exception {};

	void getInput() {
		string input;
		cout << "Please enter date (i.e. 8-27-1990)" << endl;
		scanf_s("%i-%i-%i", &month, &day, &year);
		if (!(month >= 1 && month <= 12))
		{
			throw MonthException();
		}
		if (!(day >= 1 && day <= 31))
		{
			throw DayException();
		}
		if (!(year >= 1915 && year <= 2017))
		{
			throw YearException();
		}
	}

	void printDate() {
		cout << getMonth(month) << ' ' << day << ", " << year << endl;
	}

	string getMonth(int month) {
		switch (month) {
		case 1:
			return "January";
			break;
		case 2:
			return "February";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "October";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;
		}
	}
};

int main() {
	Date date;

	while (true) {
		try
		{
			try
			{
				try
				{
					try
					{
						date.getInput();
						date.printDate();
						system("pause");
						return 0;
					}
					catch (Date::DayException e)
					{
						cout << "Invalid Day input" << endl;
						throw e;
					}
				}
				catch (Date::MonthException e)
				{
					cout << "Invalid Month input" << endl;
					throw e;
				}
			}
			catch (Date::YearException e) {
				cout << "Invalid Year Input" << endl;
				throw e;
			}
		}
		catch (...) {
			cout << "Invalid input" << endl;
		}
	}
	return 0;
}
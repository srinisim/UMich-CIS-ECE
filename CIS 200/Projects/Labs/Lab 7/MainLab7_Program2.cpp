//Program Name: Lab 7 - Program 2
//Programmer Name: Srinivas Simhan
//Description: We are using classes set via templates and learning how to implement them
//Due Date: 11/8/2017

#include <iostream>
#include <string>
using namespace std;

template <class T>
class A 
{
	T valuea;

public:

	T getValuea() const
	{
		return valuea;
	}
	
	void setValuea(T x)
	{
		valuea = x;
	}
};

template <class T>
class B : public A <T>
{
	T valueb;

public:
	B::B()
	{
		
	}
	
	T getValueb() const
	{
		return valueb;
	}

	void setValueb(T x)
	{
		valueb = x;
	}

	B(const A &instance)
	{
		valueb = getValuea();
	}
};

struct Date
{
	int day;
	int month;
	int year;
};

int main()
{
	//Float
	B<float> instance1;
	instance1.setValuea(1.34);
	cout << instance1.getValuea() << endl;
	instance1.setValueb(3.14);
	cout << instance1.getValueb() << endl;

	//Integer
	B<int> instance2;
	instance2.setValuea(1);
	cout << instance2.getValuea() << endl;
	instance2.setValueb(3);
	cout << instance2.getValueb() << endl;

	//Char
	B<char> instance3;
	instance3.setValuea('a');
	cout << instance3.getValuea() << endl;
	instance3.setValueb('c');
	cout << instance3.getValueb() << endl;

	//String
	B<string> instance4;
	instance4.setValuea("good");
	cout << instance4.getValuea() << endl;
	instance4.setValueb("bad");
	cout << instance4.getValueb() << endl;

	//Struct
	B<Date> instance5;
	instance5.setValuea({ 27, 10, 2015 });
	cout << instance5.getValuea().day << endl;
	cout << instance5.getValuea().month << endl;
	cout << instance5.getValuea().year << endl;

	instance5.setValueb({ 2, 11, 2015 });
	cout << instance5.getValueb().day << endl;
	cout << instance5.getValueb().month << endl;
	cout << instance5.getValueb().year << endl;

//	system("pause");
}
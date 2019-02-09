//Program: Lab 7 - Program 1 [CIS200, Steiner]
//Programmer Name: Srinivas Simhan
//Purpose: The purpose of the program was to learn how to use stacks to 
//manipulate values into a linked list 
//while reading and writing the values from a data file
//Date Due: 11/8/17

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <cctype>
using namespace std;

//TEMPLATE NODE
template <typename T>
struct node
{
	T val;
	node *previous;
	node *next;
};

//TEMPLATE LINKEDLIST
template <class listType>
class LinkedList
{
	//Setting pointers for linked list
public:
	node<listType> *head = NULL;
	node<listType> *curr = NULL;
	node<listType> *tail = NULL;

	//Create header, curr, and tail nodes, and attach them to each other
	void newNode(listType val)
	{
		if (head == NULL)
		{
			head = new node<listType>;
			head->previous = NULL;
			curr = head;
			curr->val = val;
			curr->previous = head;
			head->next = curr;
			tail = curr;
			curr = NULL;
		}
		else
		{
			curr = new node<listType>;
			curr->previous = tail;
			tail->next = curr;
			curr->val = val;
			tail = curr;
			curr = NULL;
		}
	}

	LinkedList()
	{
		//constructor
	}

	void reset()
	{
		head = NULL;
		curr = NULL;
		tail = NULL;
	}

	void readList()
	{
		if (head != NULL)
		{
			while (curr != NULL)
			{
				curr = head;
				cout << curr->val;
				curr = curr->next;
			}
		}
		else
		{
			cout << "Make a head node, linked list doesn't exist";
		}
	}

	listType checkTailVal()
	{
		return tail->val;
	}


};

//TEMPLATE STACK
template <class stackType>
class Stack
{
private:
	LinkedList<stackType> list;
	stackType a[5];
	int itr = 0;

public:
	void readFile(ifstream &file)
	{
		//File doesn't open
		if (file.fail())
		{
			throw "Error, file won't open.";
		}
		//File is empty
		if (file.peek() == EOF)
		{
			throw "Error, file empty.";
		}
		while (file.peek() != EOF)
		{
			if (itr > 5)
			{
				cout << "Too many values in file, decrease size to 5.";
				break;
			}
			else
			{
				file >> a[itr];
			}
			itr++;
		}
	}	

	//Checks file
	Stack(ifstream &file)
	{
		readFile(file);
	}

	//Sort values in ascending order
	void sortAscending()
	{
		bool isSorted = false;
		stackType curr;

		// while isSorted == false
			// go through whole list
				// if finding an element out of order, fix it
			// if after going through the whole list, nothing was moved, then we are done

		//Bubble Sort
		while (isSorted == false)
		{
			isSorted = true;
			for (int i = 0; i < itr; i++)
			{
				if (i != 0)
				{
					if (a[i] < a[i - 1])
					{
						isSorted = false;
						curr = a[i];
						a[i] = a[i - 1];
						a[i - 1] = curr;
					}
				}
			}
		}
	}

	//Sort values in descending order
	void sortDescending()
	{
		bool isSorted = false;
		stackType curr;

		//Bubble Sort
		while (isSorted == false)
		{
			isSorted = true;
			for (int i = 0; i < itr; i++)
			{
				if (i != 0)
				{
					if (a[i] > a[i - 1])
					{
						isSorted = false;
						curr = a[i];
						a[i] = a[i - 1];
						a[i - 1] = curr;
					}
				}
			}
		}
	}

	//Prints Highest Value
	void minMaxFunc()
	{
		cout << "Last value in this set: " << list.checkTailVal;
	}

	void putInList()
	{
		for (int i = 0; i < itr; i++)
		{
			list.newNode(a[i]);
		}
	}

	void printArray()
	{
		for (int i = 0; i < itr; i++)
		{
			cout << a[i];
		}
	}

	bool isFull()
	{
		if (itr == 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty()
	{
		if (itr == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push(stackType value)
	{
		if (isFull() == false)
		{
			a[itr] = value;
			itr++;
			node<stackType>* newNode= new node<stackType>;
			newNode->val = value;

			node<stackType>* oldHead = list.head;
			node<stackType>* newHead = newNode;

			newHead->next = oldHead;
			oldHead->previous = newHead;
			list.head = newHead;
		}
		else
		{
			cout << "Error! Full List!" << endl;
		}

		sortAscending();
	}

	void reset()
	{
		list.reset();
	}

	void readList()
	{
		list.readList();
	}

	void pop()
	{
		if (isEmpty() == false)
		{
			a[itr] = 0;
			itr--;
			list.tail->previous->next = NULL;
		}
		else
		{
			cout << "Error! No values in list" << endl;
		}
	}	
};

//MAIN FUNCTION
int main()
{
	ifstream readFile("Data.dat");
	Stack<int> listStack(readFile);
	listStack.sortAscending();
	listStack.printArray();
	cout << endl;

	listStack.sortDescending();
	listStack.printArray();
	cout << endl;
	
	listStack.putInList();
	listStack.printArray();
	cout << endl << endl << endl << endl;
	
	listStack.pop();
	listStack.printArray();
	cout << endl;
	
	listStack.push(4);
	listStack.printArray();
	cout << endl;
	
	listStack.readList();
	listStack.printArray();
	cout << endl;

	system("pause");

	return 0;
}
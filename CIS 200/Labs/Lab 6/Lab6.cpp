#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node {
	int num;
	node *next = nullptr;
	node *prev = nullptr;
	node *nextEven = nullptr;
	node *prevEven = nullptr;
};

void printListA(node* root) { //print list ascending
	if (root != nullptr) {
		cout << root->num << endl;
		printListA(root->next);
	}
}

void printListD(node* root) { //changes nullptr and root->next for reading purposes, print list descending
	if (root != nullptr) {
		printListD(root->next);
		cout << root->num << endl;
	}
}

void printListAe(node* root) { //print list ascending evens
	if (root != nullptr) {
		cout << root->num << endl;
		printListAe(root->nextEven);
	}
}

void printListDe(node* root) { //print even list descending
	if (root != nullptr) {
		printListDe(root->nextEven);
		cout << root->num << endl;
	}
}

void log(string str) {		//print onto console & into log.txt file
	ofstream logFile;
	logFile.open("log.txt");
	cout << str;
	logFile << str;
	logFile.close();
}

void insert(node* newNode, node *& root)
{
	if (root == nullptr) {	//if list is empty
		root = newNode;
	}
	else {					//if list is not empty
		if (root->num > newNode->num) { // if inserting to the left of root
			newNode->next = root;
			root->prev = newNode;
			root = newNode;
		}
		else { // if inserting to the right of root
			node* search = root; // search will be newNode's prev
			while (search->next != nullptr && search->next->num < newNode->num) {
				search = search->next;
			}
			// search is now set properly
			if (search->next != nullptr) { // not at the end?
				newNode->next = search->next;
				search->next->prev = newNode;
			}
			search->next = newNode;
			newNode->prev = search;
		}
	}
}

void insertEven(node* newNode, node *& root)
{
	if (root == nullptr) {	//if list is empty
		root = newNode;
	}
	else {					//if list is not empty
		if (root->num > newNode->num) { // if inserting to the left of root
			newNode->nextEven = root;
			root->prevEven = newNode;
			root = newNode;
		}
		else { // if inserting to the right of root
			node* search = root; // search will be newNode's prev
			while (search->nextEven != nullptr && search->nextEven->num < newNode->num) {
				search = search->nextEven;
			}
			// search is now set properly
			if (search->nextEven != nullptr) { // not at the end?
				newNode->nextEven = search->nextEven;
				search->nextEven->prevEven = newNode;
			}
			search->nextEven = newNode;
			newNode->prevEven = search;
		}
	}
}

node* remove(int intList, node*&root) {
	node *search = root;
	while ((search != nullptr) && (search->num != intList)) {
		search = search->next;
	}
	if (search == nullptr) {
		cout << "couldn't find your value :(\n";
		return nullptr;
	}
	else {
		if (search->prev == nullptr) { // nothing before s, root == search
			if (search->next == nullptr) { // nothing after s
				root = nullptr;
			}
			else { // stuff after s
				search->next->prev = nullptr;
				root = search->next;
			}
		}
		else { // stuff before s
			if (search->next == nullptr) { // nothing after s, its at the end of the list
				search->prev->next = nullptr;
			}
			else {
				search->prev->next = search->next;
				search->next->prev = search->prev;
			}
		}
		return search;
	}
}

node* removeEven(int intList, node*&root) {
	node *search = root;
	while ((search != nullptr) && (search->num != intList)) {
		search = search->nextEven;
	}
	if (search == nullptr) {
		cout << "couldn't find your value :(\n";
		return nullptr;
	}
	else {
		if (search->prevEven == nullptr) { // nothing before s, root == search
			if (search->nextEven == nullptr) { // nothing after s
				root = nullptr;
			}
			else { // stuff after s
				search->nextEven->prevEven = nullptr;
				root = search->nextEven;
			}
		}
		else { // stuff before s
			if (search->nextEven == nullptr) { // nothing after s, its at the end of the list
				search->prevEven->nextEven = nullptr;
			}
			else {
				search->prevEven->nextEven = search->nextEven;
				search->nextEven->prevEven = search->prevEven;
			}
		}
		return search;
	}
}

bool has(node * root, int searchVal) { //search the list and see if the value is already in the list
	node * search = root;
	while (search == nullptr) {
		if (search->num == searchVal) return true;
		search = search->next;
	}
	return false;
}

int main() {

	int intList;
	node *root = nullptr;
	node *evenRoot = nullptr;

	ifstream myReadFile;
	myReadFile.open("integer.dat");

	if (!myReadFile.is_open())
	{
		log("Could not open file.\n");
		return -1;
	}

	if (myReadFile.peek() == -1) { //check file empty
		log("File is empty\n");
		return -1;
	}

	while (myReadFile >> intList) {
		if (intList <= 0) {
			log("Encountered non positive integer! Continuing anyway\n");
			break;
		}
		node * newNode = new node;
		newNode->num = intList;
		insert(newNode, root);
		if (intList % 2 == 0) {
			insertEven(newNode, evenRoot);
		}
	}

	char action = 0;
	while (action != 'Q') {
		log("How to use:\n 'A': Print in Ascending Format\n 'a': Print evens in ascending format\n 'D': Print in Descending Format\n 'd': Print evens in descending format\n 'I': Insert Integer\n 'R': Remove Integer\n 'Q': Quit Program\n"); // finish with directions
		cin >> action;
	
		switch (action)
		{
		case 'A': //ascending
			log("Printed in Ascending:\n");
			printListA(root);
			break;

		case 'a': // asc evens
			log("Printed in Ascending Evens:\n");
			printListAe(evenRoot);
			break;
		
		case 'D': //descending
			log("Printed in Descending:\n");
			printListD(root);
			break;
		
		case 'd': // desc evens
			log("Printed in Descending Evens:\n");
			printListDe(evenRoot);
			break;
		
		case 'I': { //insert
			log("Input integer into list\n");
			int inputInt;
			log("What integer would you like to insert into the list?\n");
			cin >> inputInt;
			if (inputInt <= 0) {
				log("Encountered non positive integer! Continuing anyway\n");
			}
			if (has(root, inputInt)) {
				log("Value already is in list.\n");
			}
			node * newNode = new node;
			newNode->num = inputInt;
			insert(newNode, root);

			if (inputInt % 2 == 0) {
				insertEven(newNode, evenRoot);
			}
			break;
		}
		case 'R': //remove
			log("Remove integer from list\n");
			int removeInt;
			log("Which value would you like to remove?\n");
			cin >> removeInt;
			remove(removeInt, root);
			if (removeInt % 2 == 0)
			{
				removeEven(removeInt, evenRoot);
			}
			break;
		default:
			log("Please reread the directions and try again\n");
			break;
		}
	}

	cout << "Thank you for using this application! Hope to see you again!" << endl;
	return 0;
}
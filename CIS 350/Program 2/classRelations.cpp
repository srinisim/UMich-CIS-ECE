/*
   Class relations
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	Node(string label) :name(label) {}

	Node * find(string toFind) {
		Node * findPtr = nullptr;
		if (this == nullptr || this->name == toFind)
			return this;
		else {
			for (Node * nodePtr : children) {
				findPtr = nodePtr->find(toFind);
				if (findPtr != nullptr)
					return findPtr;
			}
		}//else
		return nullptr;
	}
	void print() {
		print(0);
	}
	void addChild(Node *childPtr) {
		children.push_back(childPtr);
		childPtr->extends.push_back(this);
	}
	string getName() {
		return name;
	}
private:
	string name;
	vector< Node *> children;
	vector< Node *> extends;
	void print(int level) {
		if (this != nullptr) {
			for (int i = 0; i < 5 * level; i++)
				cout << " ";
			cout << this->getName() << endl;
		}
		for (Node * ptr : children)
			ptr->print(level + 1);
	}
	
	
};

class Program {
public :
	Node * find(string name) {
		Node * foundPtr = nullptr;
		for (Node * nodePtr : classes) {
			foundPtr = nodePtr->find(name);
			if (foundPtr != nullptr)
				return foundPtr;
		}
		return nullptr;
	}
	
	void print() {
		for (Node * nodePtr : classes) {
			nodePtr->print();
			cout << "----------\n";
		}
	   }
	void add(string childName, string parentName) {
		Node * childPtr = find(childName);
		Node * parentPtr = find(parentName);
		/*if (parentName == "n") {
			cout << "adding " << childName << " extends " << parentName << endl;
			print();
		}*/
		if (parentPtr == nullptr) {
			parentPtr = new Node(parentName);
			classes.push_back(parentPtr);
			if (childPtr == nullptr) {
				childPtr = new Node(childName);
			}  // both null
			parentPtr->addChild(childPtr);
		}// parent Null, but child not in tree
		else { // parent is already in the tree
			if (childPtr == nullptr)
				childPtr = new Node(childName);
			parentPtr->addChild(childPtr);
		}
		for (int i = 0; i < classes.size(); i++)
			if (classes[i] == childPtr)
				classes.erase(classes.begin() + i);
	}//add
private:
	vector<Node *> classes;
};

int main() {
	Program program;
	string name1, name2;
	int numPairs;

	cin >> numPairs;
	for (int i = 0; i < numPairs; i++) {
		cin >> name1 >> name2;
		program.add(name1, name2);
		//program.print();
	}
	program.print();
	return 0;
}

/*
10
Date Time
Appointment Date
Calendar Appointment
Circle Point
Triangle Shape
Rectangle Shape
Square Rectangle
Cone Circle
Cylinder Circle
Circle Shape

*/

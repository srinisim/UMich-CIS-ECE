"""
    Class: CIS 350 - Winter 2018 (Elenbogen)
    Programmer: Srinivas Simhan
    Description: The purpose of this program is to create
                 and explore the relation between classes #inheritanceLife
    Due: 2/20/2018
"""

class Node:
    def __init__(self, value):
        self.child = []
        self.value = value

    def find(self, toFind):
        # print(self.value, "is looking for", toFind)
        # print("wtf", self.value, toFind, self.value is toFind)
        if(self.value == toFind):
            # print("found")
            return self
        else:
            for node in self.child:
                a = node.find(toFind)
                if a is not None:
                    return a
            return None

    def _print(self, indentLevel):
        # print("printing node", self.value)
        for i in range(indentLevel):
            print("     ", end='')
        print(self.value)
        # print("children: ", len(self.child))
        for child in self.child:
            child._print(indentLevel + 1)

    def addChild(self, childPtr):
        self.child.append(childPtr)

class Program:
    def __init__(self):
        self.roots = []

    def find(self, toFind):
        for node in self.roots:
            # print("looking for", toFind, "in root", node.value)
            a = node.find(toFind)
            if a is not None:
                return a
        return None

    def insert(self, subClass, base):
        # print("inserting",base,"->",subClass)
        basePtr = self.find(base) #base is a string
        subPtr = self.find(subClass) #subClass is a string
        # print("basePtr", basePtr)
        # print("subPtr", subPtr)
        if(basePtr is None and subPtr is None): #create a brand new tree fragment
            basePtr = Node(base)
            subPtr = Node(subClass)
            basePtr.addChild(subPtr)
            self.roots.append(basePtr)
        elif(basePtr is None and subPtr is not None):
            basePtr = Node(base)
            basePtr.addChild(subPtr)
            self.roots.append(basePtr)
            if subPtr in self.roots:
                self.roots.remove(subPtr)
        elif(basePtr is not None and subPtr is None):
            subPtr = Node(subClass)
            basePtr.addChild(subPtr)
        else: # multiple inheritance
            basePtr.addChild(subPtr)
            if subPtr in self.roots:
                self.roots.remove(subPtr)

    def printTrees(self):
        for node in self.roots:
            # print("printing root", node.value)
            node._print(0)
            print("----------")

def main():
    program = Program()

    a = int(input())

    for a in range(a):
        line = input()
        classes = line.split(' ')
        program.insert(classes[0], classes[1])

    program.printTrees()

if __name__ == "__main__":
    main()

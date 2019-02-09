# Srinivas Simhan
# CIS 350 - Elenbogen: Winter 2018
# Program 1: Nag a Ram
# Due: 1/30/18

"""
PRE:
    - cmp_to_key takes input of mycmp
POST:
    - it puts out a key that can be used for comparisons
DESCRIPTION:
    - a compare function created cause python 3 doesn't support the cmp function
"""

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K:
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K

"""
PRE:
 - x and y are lists that have at least one element in them
POST:
 - returns 1 if class x should come after class y
 - returns -1 if class x should come before class y
DESCRIPTION:
 - provides the sorting mechanism for the classes
"""
def compareClasses(x, y): # O(m)
    if len(x) == len(y):
        if x[0] < y[0]: # O(m)
            return -1
        else:
            return 1
    else: # using greater-than so they are shown in descending order
        if len(x) < len(y):
            return 1
        else:
            return -1

class EquiClasses:
    # constructor
    def __init__(self):
        self.classes = []

    """
    PRE:
        - self.classes is already defined as a list
        - each class in self.classes has at least one word
        - word is a string consisting of alphanumeric characters
    POST:
        - sort inputs into appropriate lists
    DESCRIPTION:
        - adds word to the appropriate class.
        - if no anagram class exists creates a new class.

    """
    def add(self, word): # O(n^2)
        # n -> number of words
        # m -> length of words
        wordLength = len(word)
        sortedWord = sorted(word) # O(m)
        newClassNeeded = True # until shown otherwise
        # look for an already existing class whose contents have matching word length
        for candidateClass in self.classes: # go through each class O(n) * O(n)
            candidateWord = candidateClass[0] # the first word in the class
            if len(candidateWord) == wordLength: # ignore classes whose members don't have the same length as the input word
                if sorted(candidateWord) == sortedWord: # we have our anagram O(mlogm)
                    if word not in candidateClass: # O(n)
                        candidateClass.append(word)
                    newClassNeeded = False
                    break
        if newClassNeeded:
            newClass = []
            newClass.append(word)
            self.classes.append(newClass)

    """
    PRE:
        - self.classes is already defined as a list of lists
        - word is a string consisting of alphanumeric characters
    POST:
        - sort inputs into its appropriate lists
    DESCRIPTION:
        - sorts the classes by decreasing size.
    """
    def sortClasses(self): # O(n^2logn)
        for c in self.classes: # sort each class O(n)*O(nlogn)
            c.sort() # O(nlogn)
        self.classes.sort(key=cmp_to_key(compareClasses)) # sort all classes O(nlogn*m)

    """
    PRE:
        - num2Print is not greater than the number of items in self.classes
    POST:
        - prints classes lol
    DESCRIPTION:
        - prints all the elements in the first num2Print classes
    """
    def printClasses(self, num2Print): # O(n^2), space: O(n^2m)
        for i in range(min(num2Print, len(self.classes))): # O(n) * O(n), space: O(n) * O(nm)
            c = self.classes[i]
            s = 'Class of size ' + str(len(c)) + ': ' # space: O(m)
            for word in c: # O(n), space: O(n) * O(m)
                s += word + ' ' # space: O(m)
            s += '.'
            print(s)
"""
PRE:
    - takes input list of words and classes
POST:
    - lists words in classes
DESCRIPTION:
    - program sorts words that are anagrams into classes and prints them
"""
def main():
    mn = input().split()
    numWords = int(mn[0])
    numClasses = int(mn[1])
    equiClasses = EquiClasses()
    for i in range(numWords): # O(n) * O(n^2)
        equiClasses.add(input()) # O(n^2)

    equiClasses.sortClasses()
    equiClasses.printClasses(numClasses)

if __name__ == "__main__":
    # execute only if run as a script
    main()

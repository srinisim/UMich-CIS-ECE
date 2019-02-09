def sumOfTwoNumbers(n,m):
     return n + m

def main():
    mn = input().split()
    m = int(mn[0])
    n = int(mn[1])
    s = 'The sum of ' + str(m) + ' and ' + str(n) + ' is ' + str(sumOfTwoNumbers(n,m))
    print(s)

if __name__ == "__main__":
    # execute only if run as a script
    main()


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

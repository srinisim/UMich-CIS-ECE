# Srinivas Simhan
# CIS 350 - Elenbogen: Winter 2018
# Program 4
# Due: 4/18/18

groups = []
constraints = []
ungrouped = []

def nCheck(component):
    for i in range(len(groups)):
        group = groups[i]
        if (canGroup(component, group)):
            group.append(component)

            if (len(ungrouped) > 0):
                nextComponent = ungrouped.pop()
                if (nCheck(nextComponent)):
                    return True
                else: # backtrack. undo your actions
                    popped = group.pop()
            else:
                return True

    ungrouped.append(component)

    return False

def canGroup(component, group):
    constraintsOfComponent = constraints[component - 1]
    for ungroupable in constraintsOfComponent:
        if ungroupable in group:
            return False
    return True

def main():
    nk = input().split()
    n = int(nk[0]) # number of components
    k = int(nk[1]) # number of groups
    for i in reversed(range(1,n+1)):
        ungrouped.append(i)

    for i in range(1, n+1):
        # populate noGroup with all the components i cannot be grouped with
        noGroupIds = input().split()
        noGroupIds.pop() # remove the trailing zero

        noGroup = list(map(int, noGroupIds)) # a list of the components (ints) that component i cannot be grouped with
        constraints.append(noGroup) # put this list in the constraints

    # create the groups (as empty lists)
    for i in range(k):
        group = []
        groups.append(group)

    if (nCheck(ungrouped.pop())):
        for group in groups:
            print(' '.join(map(str, group)))

    else:
        print("no solution")

if __name__ == "__main__":
    main()

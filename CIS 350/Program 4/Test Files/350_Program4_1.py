# Srinivas Simhan
# CIS 350 - Elenbogen: Winter 2018
# Program 4
# Due: 4/18/18

"""
    Test Cases:
        - Bidirectional Check
        - No Solution (state which number didn't work)

    What should our "main" routine do? Everything that we need set up to begin the problem
        + inputs
            - n and k
        + groups: list of lists of ints
            - what operations do we need our group type to do?
                - insert
                - remove
                    - Can we assume that backtracking only needs to remove the last item in a sequencial list? YES
        + ungrouped: list (stack) of ints
            - list of components yet to be inserted in a groups
        + constrains: list of sets of ints
            + i -> id of the component the constraint applies to
            + [i] -> a set of ids that component cannot be grouped with
        - actionStack: list of tuples
            - each tuple is a pairing of a component id and a group id
        - nCheck: function for taking actions and testing groupings
            - recursive method
            - return boolean:
                - TRUE if grouping is possible.
                - FALSE if grouping is not possible.
            - arguments:
                - a component from ungrouped
                - a group to put it in
            -

"""

# class Component:
#     def __init__(self, id):
#         self.id = id

groups = []
constraints = []
ungrouped = []

def nCheck(component):
    #print('nCheck', component, ungrouped)
    for i in range(len(groups)):
        group = groups[i]
        if (canGroup(component, group)):
            #print('  can group component', component, 'in group', i, group)
            group.append(component)

            # more things to group?
            if (len(ungrouped) > 0):
                #print('   more things to group')
                nextComponent = ungrouped.pop()
                if (nCheck(nextComponent)):
                    #print('    unwinding')
                    #input()
                    return True
                else: # backtrack. undo your actions
                    #print('    backtracking', component)
                    popped = group.pop()
                    #print('    removed', popped, 'from group', group)
            else:
                #print('   done')
                return True
        #else:
            #print('  cannot group component', component, 'in group', i, group)
    #print('no more groups for component', component)
    ungrouped.append(component)
    #print('put component', component, 'in ungrouped:', ungrouped)
    #input()
    return False

def canGroup(component, group):
    constraintsOfComponent = constraints[component - 1]
    # print('constraints of component:', constraintsOfComponent)
    for ungroupable in constraintsOfComponent:
        # print('ungroupable', ungroupable, 'in group', group, '?', ungroupable in group)
        if ungroupable in group:
            return False
    return True

def main():
    nk = input().split()
    n = int(nk[0]) # number of components
    k = int(nk[1]) # number of groups
    for i in reversed(range(1,n+1)):
        ungrouped.append(i)
    # ungrouped = list(reversed(range(1,n+1))) # stack of things to put together in a group

    # NOTE: if tests are failing, try doing bi-directional stuff

    # read in the constraints
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

    # print(groups)
    # print(constraints)
    # print(ungrouped)

    if (nCheck(ungrouped.pop())):
        # print groups
        for group in groups:
            print(' '.join(map(str, group)))

    else:
        print("no solution")
        # no solution


if __name__ == "__main__":
    main()

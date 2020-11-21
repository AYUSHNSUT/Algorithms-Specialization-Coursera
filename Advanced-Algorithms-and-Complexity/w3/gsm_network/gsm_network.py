# python3
import itertools

n, m = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(m) ]


# This solution prints a simple satisfiable formula
# and passes about half of the tests.
# Change this function to solve the problem.
clauses = []
vertices = range(1,n+1)

def varnum(i,j):
    return 3*(i-1) + j

def ex1of(options):
    clauses.append([o for o in options])

    for pair in itertools.combinations(options, 2):
        clauses.append([-p for p in pair])

def printEquisatisfiableSatFormula():
    for v in vertices:
        ex1of([varnum(v,j) for j in [1,2,3]])
        #print([varnum(v,j) for j in [1,2,3]])

    for e in edges:
        v1, v2 = e
        for j in [1,2,3]:
            num1 = varnum(v1,j)
            num2 = varnum(v2,j)
            lst = [-num1,-num2]
            #print(lst)
            clauses.append(lst)


    print(str(len(clauses)) + " " + str((3*n+2)))

    for c in clauses:
        for x in c:
            print(x, end = " ")
        print(0)




printEquisatisfiableSatFormula()

# colors = {}
# clauses = []
# var_num = 1
# def printEquisatisfiableSatFormula():
#     global var_num
#     for a, b in edges:
#         # At least one colors of the node must be true
#         if a not in colors:
#             colors[a] = [var_num, var_num+1, var_num+2]
#             # guarantee they're unique
#             clauses.append(' '.join(str(p) for p in colors[a]) + ' 0')
#             clauses.append('-{} -{} 0'.format(var_num, var_num+1))
#             clauses.append('-{} -{} 0'.format(var_num, var_num+2))
#             clauses.append('-{} -{} 0'.format(var_num+1, var_num+2))
#             var_num+=3
#
#         if b not in colors:
#             colors[b] = [var_num, var_num+1, var_num+2]
#             clauses.append('-{} -{} 0'.format(var_num, var_num+1))
#             clauses.append('-{} -{} 0'.format(var_num, var_num+2))
#             clauses.append('-{} -{} 0'.format(var_num+1, var_num+2))
#             # clauses.append('{} {} 0'.format(var_num, var_num+1))
#             # clauses.append('{} {} 0'.format(var_num+1, var_num+2))
#             # clauses.append('{} {} 0'.format(var_num, var_num+2))
#             var_num+=3
#             clauses.append(' '.join(str(p) for p in colors[b]) + ' 0')
#
#         # Assert each of the colors are not equal
#         for idx in range(len(colors[a])):
#             # A color and B color are not both 1 but can be 0 :)
#             clauses.append('-{} -{} 0'.format(colors[a][idx], colors[b][idx]))
#
#
# printEquisatisfiableSatFormula()
# print(len(clauses), var_num+1)
# print('\n'.join(p for p in clauses))

# python3
import itertools
n, m = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(m) ]

# This solution prints a simple satisfiable formula
# and passes about half of the tests.
# Change this function to solve the problem.
clauses = []
vertices = range(1,n+1)
paths = range(1,n+1)
s_p = range(1,n)

adj = [[] for _ in range(n)]
for i, j in edges:
    adj[i-1].append(j-1)
    adj[j-1].append(i-1)


def varnum(i,j):
    return i*n + j

def ex1of(options):
    clauses.append([o for o in options])

    for pair in itertools.combinations(options, 2):
        clauses.append([-p for p in pair])


def printEquisatisfiableSatFormula():
    for v in s_p:
        ex1of([varnum(v,j) for j in paths])

    for p in paths:
        ex1of([varnum(p,j) for j in s_p])

    for j in range(n):
        for i, nodes in enumerate(adj):
            clauses.append([-varnum(i, j)] + [varnum(n, j+1) for n in nodes])

    print(len(clauses), n*n)
    for c in clauses:
        c.append(0)
        print(' '.join(map(str, c)))





printEquisatisfiableSatFormula()

import itertools

n, m = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(m) ]

clauses = []
positions = range(1, n+1)
adj = [[] for _ in range(n)]
for i, j in edges:
    adj[i-1].append(j-1)
    adj[j-1].append(i-1)

def var_number(i, j):
    return n*i + j

def exactly_One_Of(literals):
    clauses.append([l for l in literals])
    for pair in itertools.combinations(literals, 2):
        clauses.append([-l for l in pair])

for i in range(n):
    exactly_One_Of([var_number(i, j) for j in positions])

for j in positions:
    exactly_One_Of([var_number(i, j) for i in range(n)])

for j in positions[:-1]:
    for i, nodes in enumerate(adj):
        clauses.append([-var_number(i, j)] + [var_number(n, j+1) for n in nodes])

print(len(clauses), n*n)
for c in clauses:
    c.append(0)
    print(' '.join(map(str, c)))

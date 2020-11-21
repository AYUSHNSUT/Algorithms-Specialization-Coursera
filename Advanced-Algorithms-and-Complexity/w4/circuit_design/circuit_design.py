# python3
import sys
import threading

sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**25)  # new thread will get stack of such size

def getVertex(x,n):
	if(x>0):
		return x
	else:
		return n - x;

def PostOrder(i, graph, visited, post):
    global clock
    visited[i] = True
    for v in graph[i]:
        if not visited[v]:
            PostOrder(v, graph, visited, post)
    post[i] = clock
    clock += 1


def DFS(n, graph):
    global clock
    visited = [False] * (2 * n + 1)
    post = [0] * (2 * n + 1)
    for v in range(1, 2 * n + 1):
        if not visited[v]:
            PostOrder(v, graph, visited, post)
    post = list(enumerate(post[1:], start=1))
    post.sort(key=lambda x:x[1], reverse=True)
    post_vertex = []
    for v, order in post:
        post_vertex.append(v)
    return post_vertex


def Explore(i, graph, visited, SCC, SCC_number, u):
    visited[i] = True
    SCC.append(i)
    SCC_number[i] = u
    for v in graph[i]:
        if not visited[v]:
            Explore(v, graph, visited, SCC, SCC_number, u)

def FindSCCs(n, adj, adjr):
    global clock
    post_vertex = DFS(n, adjr)
    visited = [False] * (2 * n + 1)
    SCCs = []
    SCC_number = [0] * (2 * n + 1)
    u = 1
    for i in post_vertex:
        if not visited[i]:
            SCC = []
            Explore(i, adj, visited, SCC, SCC_number, u)
            SCCs.append(SCC)
            u += 1
    return SCCs, SCC_number


def TwoSAT(n, adj, adjr):
    SCCs, SCC_number = FindSCCs(n, adj, adjr)
    # print(SCCs, SCC_number)
    for i in range(1, n + 1):
        if SCC_number[i] == SCC_number[i + n]:
            return False
    solution = [[] for _ in range(2 * n + 1)]
    assigned = [False] * (2 * n + 1)
    for SCC in SCCs:
        for v in SCC:
            if not assigned[v]:
                assigned[v] = True
                solution[v] = 1
                if v > n:
                    solution[v - n] = 0
                    assigned[v - n] = True
                else:
                    solution[v + n] = 0
                    assigned[v + n] = True
    return solution


clock = 1
def main():
    n, m = map(int, input().split())
    adj = [[] for _ in range(2 * n + 1)]
    adjr = [[] for _ in range(2 * n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        v1 = getVertex(a,n)
        v2 = getVertex(b,n)
        nv1 = getVertex(-a,n)
        nv2 = getVertex(-b,n)
        adj[nv1].append(v2)
        adjr[v2].append(nv1)
        adj[nv2].append(v1)
        adjr[v1].append(nv2)
    # print(edges)
    # print(rev_edges)
    result = TwoSAT(n, adj, adjr)
    if not result:
        print('UNSATISFIABLE')
    else:
        print('SATISFIABLE')
        for i in range(1, n + 1):
            if result[i] > 0:
                print(i, end=' ')
            else:
                print(-i, end=' ')


threading.Thread(target=main).start()
#python3
def printCircuit(adj):
    edge_count = dict()

    for i in range(len(adj)):
        edge_count[i] = len(adj[i])

    if len(adj) == 0:
        return

    # Maintain a stack to keep vertices
    curr_path = []

    # vector to store final circuit
    circuit = []

    # start from any vertex
    curr_path.append(0)
    curr_v = 0 # Current vertex

    while len(curr_path):

        # If there's remaining edge
        if edge_count[curr_v]:

            # Push the vertex
            curr_path.append(curr_v)

            # Find the next vertex using an edge
            next_v = adj[curr_v][-1]

            # and remove that edge
            edge_count[curr_v] -= 1
            adj[curr_v].pop()

            # Move to next vertex
            curr_v = next_v

        # back-track to find remaining circuit
        else:
            circuit.append(curr_v)

            # Back-tracking
            curr_v = curr_path[-1]
            curr_path.pop()

    # we've got the circuit, now print it in reverse
    for i in range(len(circuit) - 1, -1, -1):
        if(i!=0):
            print(circuit[i] + 1, end = " ")
        # if i:
        #     print(" -> ", end = "")


n , m = [int(i) for i in input().split()]
# print(n);
# print(m)

adj = [[] for _ in range(n)]
indegree = [0 for _ in range(n)]
outdegree = [0 for _ in range(n)]

for i in range(m):
    x , y = [int(i) for i in input().split()]
    adj[x-1].append(y-1)
    indegree[y-1] += 1
    outdegree[x-1] += 1


flag = 1
for i in range (n):
    if(indegree[i]!= outdegree[i]):
        flag = 0

if(flag == 0):
    print(0)
else:
    print(1)
    printCircuit(adj)
#printCircuit(adj)

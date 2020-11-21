# python3

import sys
import itertools


class dbGraph:

     def __init__(self, k, t, reads):
         self.k = k
         self.reads = reads
         self.t = t;
         self.graph = {}
         self.paths = {}
         self.Kmers = []
         self.leftNodesIn = []
         self.rightNodesOut = set()
         self.totalBubbles = 0


     def makeKmers(self):
        k_temp = set()
        for i in range(len(self.reads)):
            for j in range(len(self.reads[i]) - self.k + 1):
                # print(j)
                # print(reads[i][j:j+self.k])
                k_temp.add(reads[i][j:j+self.k]);

            # itr = 0
            # for j in range(len(self.reads[i]) - self.k + 1, len(self.reads[i])):
            #     #print(reads[i][j:j+self.k] + reads[i][0:itr+1])
            #     k_temp.add(reads[i][j:j+self.k] + reads[i][0:itr+1])
            #     itr+=1

        for a in k_temp:
            self.Kmers.append(a)


     def makeGraph(self):

        #print(self.Kmers)
        def ins(graph, leftNode, rightNode):
            graph.setdefault(leftNode, [set(), 0])
            graph.setdefault(rightNode, [set(), 0])

            if rightNode not in graph[leftNode][0]:
                graph[leftNode][0].add(rightNode)
                graph[rightNode][1] += 1
                # graph[leftNode][1] += 1

        for oneKmer in self.Kmers:
            leftKmer = oneKmer[:-1]
            rightKmer = oneKmer[1:]

            if(leftKmer != rightKmer):
                ins(self.graph,leftKmer,rightKmer)


     def prepNodes(self):

            for x, y in self.graph.items():
                if (len(y[0]) > 1 ):
                    self.leftNodesIn.append(x)

                if(y[1] > 1):
                    self.rightNodesOut.add(x)


     def get_bubbles(self):

            #print(self.graph)

            def dispair(pair):
                return len(set(pair[0]).intersection(set(pair[1]))) == 2


            for x,y in self.graph.items():
                if len(self.graph[x][0]) > 1:
                    # print(x)
                    # print(len(self.graph[x][0]))
                    self.dfs(path = [x], start = x, current = x,depth = 0)


            for x,y in self.paths.items():
                # print(x, end = "")
                # print(y)
                for pair in itertools.combinations(y, r= 2):
                    if dispair(pair) and (len(pair[0]) <= self.t + 1) and (len(pair[1]) <= self.t + 1) :
                        #and len(pair[0]) > 2 and len(pair[1]) > 2
                        # print(pair)
                        # print(len(pair[0]))
                        # print(len(pair[1]))
                        # print(self.t)
                        self.totalBubbles +=1







     def dfs(self, path, start, current, depth):
        if current != start and (self.graph[current][1] > 1):
            self.paths.setdefault((start, current), list()).append(path[:])

        if depth == self.t:
            return

        for x in self.graph[current][0]:
            if x not in path:
                path.append(x)
                #print("appending" + str(x))
                self.dfs(path, start, x, depth + 1)
                #print("deappending" + str(x))
                path.remove(x)


data = sys.stdin.read().split()
k, t, reads = data[0], data[1], data[2:]
# k, t = input().split()
# reads = []
# for i in range(3):
#     reads.append(input())
setReads = set()
for x in reads:
    setReads.add(x)
uniqueReads = []
for x in setReads:
    uniqueReads.append(x)
#print(uniqueReads)
#print(t)
db = dbGraph(int(k),int(t),reads)
db.makeKmers()
db.makeGraph()
db.get_bubbles()
print(db.totalBubbles)

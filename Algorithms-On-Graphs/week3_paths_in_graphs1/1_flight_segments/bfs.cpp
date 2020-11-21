#include <iostream>
#include <vector>
#include <queue>

#define DEBUG(x) std::cout << (#x) << " is " << (x) << std::endl

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  if(s==t)
    return 0;

  queue <int> Q;
  vector <int> visited(adj.size());
    vector <int> dist(adj.size());
    for(int i = 0;i<dist.size();i++)
    {
      dist[i] = 1e8;
    }
  Q.push(s);
  visited[s] = 1;
  dist[s] = 0;

  while(!Q.empty())
  {

    int v = Q.front();
    Q.pop();


    for(auto i: adj[v])
    {
      if(i==t)
        {
          dist[i] = dist[v] + 1;
          return dist[i];
        }

      if(visited[i]==0)
      {
        Q.push(i);
        dist[i] = dist[v] + 1;
          visited[i] = 1;
      }
    }


  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::make_pair;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector <int> dist(adj.size());
    vector <int> prev(adj.size());
    priority_queue <pair <int,int>, vector <pair<int,int>>, std::greater<pair<int,int>>> res;

  for(int i = 0;i<adj.size();i++)
  {
    dist[i] = INT_MAX;
    prev[i] = -1;

  }
  dist[s] = 0;
  res.push(make_pair(dist[s],s));

  while(!res.empty())
  {
    int u = res.top().second;
    res.pop();

    for(int i = 0; i < adj[u].size();i++)
    {
      int v = adj[u][i];
      if(cost[u][i] + dist[u] < dist[v])
      {
        dist[v]  = cost[u][i] + dist[u];
        res.push(make_pair(dist[v],v));
      }
    }
  }

  if(dist[t] == INT_MAX)
  return -1;
  else
    return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}

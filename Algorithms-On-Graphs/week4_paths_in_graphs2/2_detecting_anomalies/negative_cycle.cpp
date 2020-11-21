#include <iostream>
#include <vector>
#include <climits>

#define DEBUG(x) std::cout << (#x) << " is " << (x) << std::endl

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here


  vector <long long> dist(adj.size());

  for(int i = 0;i<adj.size();i++)
  {
      dist[i] = INT_MAX;
  }

//  dist[0] = 0;

  for(int m = 0;m<adj.size();m++)
  {
      int updates = 0;
      if(dist[m] = INT_MAX)
        dist[m] = 0;

//      DEBUG(m);
      for(int i = 0;i<adj.size();i++)
      {
//        DEBUG(i);
        for(int j = 0;j<adj[i].size();j++)
        {
          int v = adj[i][j];
          // DEBUG(v);
          // DEBUG(dist[v]);
          // DEBUG(dist[i]);
          // DEBUG(cost[i][j]);
          if(dist[v] > dist[i] + cost[i][j] )
          {
            dist[v] = dist[i] + cost[i][j];
            updates++;
          }
        }
      }
  //    printf("%d Updates in iteration m = %d\n",updates,m);
    //  DEBUG()

  }
  int up = 0;
  for(int i = 0;i<adj.size();i++)
  {
//        DEBUG(i);
    for(int j = 0;j<adj[i].size();j++)
    {
      int v = adj[i][j];
      // DEBUG(v);
      // DEBUG(dist[v]);
      // DEBUG(dist[i]);
      // DEBUG(cost[i][j]);
      if(dist[v] > dist[i] + cost[i][j] )
      {
        dist[v] = dist[i] + cost[i][j];
        up++;
      }
    }
  }

  if(up)
    return 1;




  return 0;
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
  std::cout << negative_cycle(adj, cost);
}

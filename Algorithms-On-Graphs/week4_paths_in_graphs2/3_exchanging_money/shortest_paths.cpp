#include <iostream>
#include <climits>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

#define DEBUG(x) std::cout << (#x) << " is " << (x) << std::endl


void reachablee(vector<vector<int> > &adj, int s,vector<int> &reachable)
{

  queue <int> Q;
  vector <long long> diss(adj.size());

  for(int i = 0;i<diss.size();i++)
  {
    diss[i] = INT_MAX;
  }

  Q.push(s);

  diss[s] = 0;

  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();
    for(auto i: adj[v])
    {
      if(diss[i]==INT_MAX)
      {
        Q.push(i);
        diss[i] = diss[v] + 1;
      }
    }
  }

  for(int i = 0;i<adj.size();i++)
  {
    if(diss[i] != INT_MAX)
      reachable[i] = 1;
  }


}


void negative_cycle(vector<vector<int> > &adj,vector <int> &reachable, vector <int> &shortest, vector <vector <int>> &cost, int s,vector <long long> &dist) {
  //write your code here

  for(int i = 0;i<adj.size();i++)
  {
      dist[i] = INT_MAX;
  }

  dist[s] = 0;
  vector <int> changes(adj.size());

  for(int m = 0;m<=adj.size() +1;m++)
  {
    int updates = 0;
      for(int i = 0;i<adj.size();i++)
      {
        if(!reachable[i])
          continue;
        for(int j = 0;j<adj[i].size();j++)
        {
          int v = adj[i][j];

          if(dist[v] > dist[i] + cost[i][j] )
          {
            dist[v] = dist[i] + cost[i][j];
            updates++;

          }
        }
      }
  }

  for(int i = 0;i<adj.size();i++)
  {
    if(!reachable[i])
      continue;
    for(int j = 0;j<adj[i].size();j++)
    {
      int v = adj[i][j];

      if(dist[v] > dist[i] + cost[i][j] )
      {
        dist[v] = dist[i] + cost[i][j];
        shortest[i] = 0;
        shortest[v] = 0;

      }
    }
  }



}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here

// for reachable

  reachablee(adj,s,reachable);

  // for negative_cycle
  vector <long long> dist(adj.size());
negative_cycle(adj,reachable,shortest,cost,s,dist);

  vector <int> dummy(adj.size());
  for(int i = 0;i<adj.size();i++)
  {
      if(reachable[i] == 1 && shortest[i] == 0)
      {
        reachablee(adj,i,dummy);
      }
  }

  for(int i = 0;i<adj.size();i++)
  {
      if(dummy[i] == 1)
        shortest[i] =0;
  }


  for(int i = 0;i<adj.size();i++)
  {

    if(shortest[i] == 1 && reachable[i] == 1)
    {
      distance[i] = dist[i];
    }
  }

}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);

  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}

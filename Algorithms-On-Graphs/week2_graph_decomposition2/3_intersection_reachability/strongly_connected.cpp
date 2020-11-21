#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

#define DEBUG(x) std::cout << (#x) << " is " << (x) << std::endl

void dfs(vector<vector<int> > &adj, std::vector<int> &visited, stack<int> &order, int x) {
  //write your code here
  visited[x] = 1;

  for(auto i: adj[x])
  {
    if(visited[i] == 0)
      dfs(adj,visited,order,i);
  }
  // /DEBUG(x);
  order.push(x);

}

int number_of_strongly_connected_components(vector<vector<int> > adj,vector<vector<int> > &adjr) {
  int result = 0;
  vector <int> visited1(adj.size());
  vector <int> visited2(adj.size());
  stack <int> order;
  stack <int> dummy;
  //write your code here
  for(int i = 0;i<adj.size();i++)
  {
    if(visited1[i]==0)
    {
      dfs(adj,visited1,order,i);
    }
  }


  while(!order.empty())
  {
    int z = order.top();
    order.pop();
    if(visited2[z]==0)
    {
      dfs(adjr,visited2,dummy,z);
      result++;
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adjr(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjr[y-1].push_back(x-1);
  }
  std::cout << number_of_strongly_connected_components(adj,adjr);
}

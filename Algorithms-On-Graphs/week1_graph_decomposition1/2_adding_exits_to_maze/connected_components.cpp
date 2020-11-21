#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::pair;

void dfs(int x,int classs,vector <int> &visited,vector<vector<int> > &adj)
{
	visited[x]=classs;
	for(int i = 0;i<adj[x].size();i++)
	{
		if(visited[adj[x][i]]==0)
		{
			dfs(adj[x][i],classs,visited,adj);
		}
	}
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  int classs = 1;
  //write your code here
//  printf("adj size %d\n",adj.size());
  vector <int> visited(adj.size());
  for(int i = 0;i<adj.size();i++)
  {
    if(visited[i] == 0)
      {
        dfs(i,classs,visited,adj);
        classs++;
      }
  }
  std::set <int> res_set;
  for(auto s:visited)
    res_set.insert(s);
  return res_set.size();
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }


  std::cout << number_of_components(adj);
}

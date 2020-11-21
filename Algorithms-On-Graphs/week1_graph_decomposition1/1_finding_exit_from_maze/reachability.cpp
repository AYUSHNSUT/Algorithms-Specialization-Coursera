#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

int dfs(vector<vector<int> > &adj, int x,int y,vector <int> &visited)
{
	visited[x]=1;
	for(int i = 0;i<adj[x].size();i++)
	{
//    printf("check i = %d\n",adj[x][i]);
    if(adj[x][i] == y)
      return 1;
		if(visited[adj[x][i]]==0)
		{
    //  printf("Visitng %d\n",i);
			int z = dfs(adj,adj[x][i],y,visited);
      if(z)
        return 1;
		}
	}

  return 0;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector <int> visited(adj.size()+1);
  int z = dfs(adj,x,y,visited);
  return z;

//  return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}

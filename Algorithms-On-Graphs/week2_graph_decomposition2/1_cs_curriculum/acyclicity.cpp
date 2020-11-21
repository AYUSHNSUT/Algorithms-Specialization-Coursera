#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::pair;

#define DEBUG(x) std::cout << (#x) << " is " << (x) << std::endl

// void bfs(int x, int &flag, vector <int> &visited, vector<vector<int> > &adj)
// {
//   visited[x]
// }

bool dfs(int x, vector <int> &visited, vector<vector<int> > &adj, map <int,int> &mp)
{
	visited[x]=true;
	mp[x] = 1;
	for(auto i : adj[x])
	{
		if(visited[i]==false)
		{
			bool res =  dfs(i,visited,adj,mp);
			if(res)
				return 1;
		}
    else if (mp[i] == 1)
    {
  //    DEBUG(x);
    //  DEBUG(parent);
  //    DEBUG(i);

			// for(auto p: mp)
			// 	std::cout << p.first << " "<<p.second << std::endl;
      return 1;


    }
	//	mp[i] = 0;

	}

  mp[x] = 0;
	return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector <int> visited(adj.size());
  int flag = 0;
	map <int,int> mp;
  for(int i = 0;i<adj.size()&& flag == 0;i++)
  {
    if(visited[i]==0)
    {

    	if(dfs(i, visited,adj,mp))
				return 1;
    }
  }
  return flag;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}

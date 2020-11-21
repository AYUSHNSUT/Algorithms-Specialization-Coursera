#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int check(vector<vector<int> > &adj,int x, vector <int> &colour)
{
   queue <int> Q;

    Q.push(x);

    colour[x] = 1;
//    vector <int> visited(adj.size());
  //  visited[0] = 1;
        while(!Q.empty())
        {

          int v = Q.front();
          Q.pop();


          for(auto i: adj[v])
          {

            if(colour[i] == -1)
            {
              colour[i] = 1 - colour[v];
              Q.push(i);
            }
            else if(colour[i] == colour[v])
              return 0;


          }


        }

        return  1;

}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  queue <int> Q;
//  vector <int> visited(adj.size());
    vector <int> colour(adj.size());

    for(int i = 0;i<colour.size();i++)
    {
      colour[i] = -1;
    }

    for(int i = 0;i<adj.size();i++)
    {
      if(colour[i] == -1)
      {int ans = check(adj,i,colour);

      if(!ans)
        return 0;
}

    }


  return 1;
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
  std::cout << bipartite(adj);
}

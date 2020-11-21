#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << std::endl;

int getVertex(int x){
  if(x > 0 ){
    return x;
  }
  else{
    return n + abs(x);
  }
}

int getClause(int x){
  if(x > n)
  {
    return n-x;
  }
  else{
    return x;
  }
}


void dfs(vector<vector<int> > &adj, std::vector<int> &visited, stack<int> &order, int x, int res = 1) {
  //write your code here
  visited[x] = res;

  for(auto i: adj[x])
  {
    if(visited[i] == 0)
      dfs(adj,visited,order,i);
  }
  // /DEBUG(x);
  order.push(x);

}

void rdfs(vector<vector<int> > &adj, std::vector<int> &visited, int x, int res = 1, std::vector<int> scc,  std::vector<int> scc_num) {
  //write your code here
  visited[x] = res;
  scc.push_back(x);
  scc_num[x] = res;
  for(auto i: adj[x])
  {
    if(visited[i] == 0)
      rdfs(adj,visited2,i, result, scc, scc_num);
  }
  // /DEBUG(x);
  order.push(x);

}

pair <vector <int>, std::vector<int>> number_of_strongly_connected_components(int n, vector<vector<int> > adj,vector<vector<int> > &adjr) {
  int result = 0;
  vector <int> visited1(adj.size());
  vector <int> visited2(adj.size());
  stack <int> order;
  stack <int> dummy;
  //write your code here
  for(int i = 0;i<adjr.size();i++)
  {
    if(visited1[i]==0)
    {
      dfs(adjr,visited1,order,i);
    }
  }
  vector <int> scc_num(2*(n+1));


  vector <std::vector<int>> SSCs;
  while(!order.empty())
  {
    int z = order.top();
    order.pop();
    if(visited2[z]==0)
    {
      vector <int> scc;
      rdfs(adj,visited2,z, result+1, scc, scc_num);
      SSCs.push_back(scc);
      result++;
    }
  }
  return make_pair(SSCs, scc_num) ;
}


std::vector<int> SAT(int n, vector <vector <int>> adj,  vector <vector <int>> adjr){
  pair <vector <int>, vector<int>> p;
  p = number_of_strongly_connected_components(n,adj,adjr);
  std::vector<int> SCCs = p.first;
  std::vector<int> scc_num = p.second;

  vector <int> v;
  for(int i = 1;i<n+1;j++){
    if(scc_num[i] == scc_num[i+n]){
      return v;
    }
    else{
      
    }
  }
}

struct Clause {
    int firstVar;
    int secondVar;
};

struct TwoSatisfiability {
    int numVars;
    vector<Clause> clauses;

    TwoSatisfiability(int n, int m) :
        numVars(n),
        clauses(m)
    {  }

    bool isSatisfiable(vector<int>& result) {
      std::vector<vector <int>> adj(2* (numVars + 1)),adjr(2*(numVars + 1));

        for(int i = 0;i<clauses.size();i++){
          int v1 = clauses[i].firstVar;
          int v2 = clauses[i].secondVar;
          int x1 = getVertex(v1);
          int x2 = getVertex(v2);
          int nx1 = getVertex(-v1);
          int nx2 = getVertex(-v2);
          adj[nx1] = x2;
          adjr[x2] = nx1;
          adj[nx2] = nx1;
          adjr[nx1] = nx2;
        }


        result = SAT(numVars, adj, adjr);



    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    TwoSatisfiability twoSat(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> twoSat.clauses[i].firstVar >> twoSat.clauses[i].secondVar;
    }

    vector<int> result(n+1);
    if (twoSat.isSatisfiable(result)) {
        cout << "SATISFIABLE" << endl;
        for (int i = 1; i <= n; ++i) {
            if (result[i-1]) {
                cout << -i;
            } else {
                cout << i;
            }
            if (i < n) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    } else {
        cout << "UNSATISFIABLE" << endl;
    }

    return 0;
}

/*
original bruteforce
// This solution tries all possible 2^n variable assignments.
// It is too slow to pass the problem.
// Implement a more efficient algorithm here.
// for (int mask = 0; mask < (1 << numVars); ++mask) {
//     for (int i = 0; i < numVars; ++i) {
//         result[i] = (mask >> i) & 1;
//     }
//
//     bool formulaIsSatisfied = true;
//
//     for (const Clause& clause: clauses) {
//         bool clauseIsSatisfied = false;
//         if (result[abs(clause.firstVar) - 1] == (clause.firstVar < 0)) {
//             clauseIsSatisfied = true;
//         }
//         if (result[abs(clause.secondVar) - 1] == (clause.secondVar < 0)) {
//             clauseIsSatisfied = true;
//         }
//         if (!clauseIsSatisfied) {
//             formulaIsSatisfied = false;
//             break;
//         }
//     }
//
//     if (formulaIsSatisfied) {
//         return true;
//     }
// }
// return false;
*/

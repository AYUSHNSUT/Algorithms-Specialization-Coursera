#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <map>

using std::vector;
using std::pair;
using std::map;
using std::make_pair;

typedef pair <int,int> pii;

class DisjSet {
    int *rank, *prnt, n;

public:

    DisjSet(int n)
    {
        rank = new int[n];
        prnt = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            prnt[i] = i;

        }
    }

    int find(int x)
    {

        if (prnt[x] != x) {

            prnt[x] = find(prnt[x]);

        }

        return prnt[x];
    }


    void Union(int x, int y)
    {
        int set1 = find(x);
        int set2 = find(y);

        if (set1 == set2)
            return;

        if (rank[set1] < rank[set2]) {
            prnt[set1] = set2;
        }
        else if (rank[set1] > rank[set2]) {
            prnt[set2] = set1;
        }

        else {
            prnt[set2] = set1;
            rank[set1] = rank[set1] + 1;
        }
    }
};


double d(pii P1, pii P2)
{
  double a1 = P1.first - P2.first;
    double a2 = P1.second - P2.second;

    return sqrt(a1 * a1 + a2* a2);
}


double clustering(map <pii,double> cost, int k, int n) {
  //write your code here

  vector <pair<double,pii>> tmp;
  //write your code here
  for(auto m: cost)
  {
    tmp.push_back(make_pair(m.second,m.first));
  }

  std::sort(tmp.begin(),tmp.end());


    DisjSet dj(n);
    int count = 0;
    for(int i = 0;i<tmp.size();i++)
    {
      pii t = tmp[i].second;
      int k1 =  t.first;
      int k2 = t.second;

      if(dj.find(k1)!=dj.find(k2) && count == n-k)
      {
        return tmp[i].first;
      }

      if(dj.find(k1)!=dj.find(k2))
      {
        dj.Union(k1,k2);
        count++;
      }
      // else
      //   printf("%d %d are already connected\n",k1,k2);
    }

  return -1.;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector <pair <int,int>> P(n);
  vector<int> x(n), y(n);
  map <pii,double> cost;
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
    P[i] = std::make_pair(x[i],y[i]);
  }

  for(int i = 0;i<n;i++)
  {
      for(int j = i+1; j<n;j++)
      {
          double c = d(P[i],P[j]);
          cost[make_pair(i,j)] = c;
      }
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(cost,k,n) << std::endl;
}

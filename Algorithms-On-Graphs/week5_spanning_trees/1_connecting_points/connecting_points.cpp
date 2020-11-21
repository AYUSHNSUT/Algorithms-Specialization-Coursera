#include <algorithm>
#include <iostream>
#include <iomanip>
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

double minimum_distance(map<pii,double> cost,int n)
{
  double result = 0.;
  vector <pair<double,pii>> tmp;
  //write your code here
  for(auto m: cost)
  {
    tmp.push_back(make_pair(m.second,m.first));
  }

  std::sort(tmp.begin(),tmp.end());


    // for(auto m: tmp)
    // {
    //   printf("%d %d ka cost %f\n", m.second.first,m.second.second, m.first);
    // }


  DisjSet dj(n);

  for(int i = 0;i<tmp.size();i++)
  {
    pii t = tmp[i].second;
    int k1 =  t.first;
    int k2 = t.second;

    if(dj.find(k1)!=dj.find(k2))
    {
      dj.Union(k1,k2);
      result += tmp[i].first;
    }
    // else
    //   printf("%d %d are already connected\n",k1,k2);
  }



  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  vector <pair <int,int>> P(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
    P[i] = std::make_pair(x[i],y[i]);
  }
  map <pii,double> cost;
  if(n ==  1)
    std::cout << 0 << std::endl;
  else
  {
  for(int i = 0;i<n;i++)
  {
      for(int j = i+1; j<n;j++)
      {
          double c = d(P[i],P[j]);
          cost[make_pair(i,j)] = c;
      }
  }


  std::cout << std::setprecision(11) << minimum_distance(cost,n) << std::endl;
}
}

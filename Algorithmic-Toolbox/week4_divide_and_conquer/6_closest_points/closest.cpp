#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

typedef long long ll;

using std::vector;
using std::string;
using std::pair;
using std::min;
using std::make_pair;

double d(ll x1,ll y1,ll x2,ll y2)
{
  return sqrt((x1-x2) * (x1-x2) + (y1-y2)*(y1-y2));
}

double minimal_distance(vector<pair<ll,ll>> x, vector<pair<ll,ll>> y) {
  //write your code here

  // for(int i = 0;i<x.size();i++)
  // {
  //   printf("%d ( %d %d )\n", x[i].second,x[i].first,y[i].first);
  // }





  if(x.size()==3)
  {
    double m1 = d(x[0].first,y[0].first,x[1].first,y[1].first);;
    double m2 = d(x[2].first,y[2].first,x[1].first,y[1].first);
  //  printf("Size 3 pe aa gaye \n");
    double m = min(m1,m2);
//    printf("m11,m22,m23 are %f %f %f\n",m1,m2,d(x[0].first,y[0].first,x[2].first,y[2].first));
    return min(m,d(x[0].first,y[0].first,x[2].first,y[2].first));
  }
  else if(x.size()==2)
  {
//    printf("Size 2 pe aa gaye \n");
//    printf("distance is %f\n", d(x[0].first,y[0].first,x[1].first,y[1].first) );
    // printf("point 1 is %d %d \n", x[0].first, y[0].first);
    // printf("point 2 is %d %d \n" ,x[1].first, y[1].first);
    return d(x[0].first,y[0].first,x[1].first,y[1].first);
  }
  else if(x.size()==1)
  {
    return 0;
  }
  else if(x.size()==0)
  {
    return 1e18;
  }
  else
  {
  //  printf("Else pe aa gaye\n");
    ll middle = x.size()/2;
    vector <pair<ll,ll>> Qx,Qy,Rx,Ry;

    for(ll i = 0;i<middle;i++)
    {
      Qx.push_back(x[i]);
      Qy.push_back(y[i]);

    }

    for(ll i = middle;i<x.size();i++)
    {
      Rx.push_back(x[i]);
      Ry.push_back(y[i]);

    }

    double d1 = minimal_distance(Qx,Qy);
    double d2 = minimal_distance(Rx,Ry);

    double df = min(d1,d2);

//    printf("DF is %d\n", df);

    ll line = (x[middle-1].first + x[middle].first)/2;

  //  printf("Proposed Middle line is %d\n",line);

    vector < pair <ll,ll>> S;
    ll iter = -1;
    for(auto Pts: x)
    {
      iter++;
      if (Pts.first>= (line - df) && Pts.first  <= line + df)
      {
        S.push_back(make_pair(y[iter].first,x[iter].first));
      }

    }
    double d3 = df;

    sort(S.begin(),S.end());
    for(ll i = 0;i<S.size();i++)
    {

      for(ll j = i+1;j<=i+9 && j<S.size();j++)
      {
        d3 = min(d3,d(S[i].first,S[i].second,S[j].first,S[j].second));
      }
    }

    return min(d3,df);


    }
  return 0.;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  vector <pair <ll,ll>> X(n);
  vector <pair <ll,ll>> Y(n);
  vector <pair <ll,ll>> P(n);

  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
    P[i] = make_pair(x[i],y[i]);
  }
    sort(P.begin(),P.end());

  for(ll i = 0;i<x.size();i++)
  {
    X[i] = make_pair(P[i].first,i);
    Y[i] = make_pair(P[i].second,i);

  }


  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(X, Y) << "\n";
}

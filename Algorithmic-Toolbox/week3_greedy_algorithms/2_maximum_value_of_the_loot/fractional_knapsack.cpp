#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using std::vector;
using std::pair;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector <pair <double,int> > v(weights.size());

  // for (auto x : weights)
  //   cout << x<< endl;
  //   for (auto x : values)
  //     cout << x<< endl;

  for(int i = 0;i<weights.size();i++)
  {
    pair <double,int> p;
    p.first = (double)values[i]/weights[i];
  //  cout << p.first << endl;
    p.second = i;
    v[i] = p;
  }



  std::sort(v.rbegin(),v.rend());

  // for(auto x: v)
  //   cout << x.first << " " << x.second << endl;

  int put = 0;
  double ans = 0;
//  cout << "25\n";
  for(int i = 0;i<weights.size();i++)
  {
    if(put == capacity)
    break;

    int ind = v[i].second;
    int weigh = weights[ind];
    double val = values[ind];
    int left = capacity - put;
    if(left >= weigh)
    {
      ans += val ;
      put += weigh;

    }
    else
    {
      ans += (double)(val/weigh ) * left ;
      put += left;
    }


  }
  // write your code here

  return ans;
}

int main() {
  int n;
  //cout << "ajkjakljfa\n";

  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  //cout << "ajkjakljfa\n";

  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
//  cout << "ajkjakljfa\n";

  double optimal_value = get_optimal_value(capacity, weights, values);
//  std::cout << optimal_value;
  //cout << "ajkjakljfa\n";

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
/*
3 50
60 20
100 50
120 30
*/

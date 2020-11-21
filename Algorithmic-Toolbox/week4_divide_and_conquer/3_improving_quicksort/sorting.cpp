#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <stack>

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

using std::vector;
using std::swap;
using std::pair;
using std::stack;
using std::cout;
using std::endl;
// 2 4 5 2 1
 pair<int,int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  vector <int> smol,med,large;

  for(int i = l;i<=r;i++)
  {
    if(a[i]<x)
      smol.push_back(a[i]);
    else if (a[i]== x)
    {
      med.push_back(a[i]);
    }
    else
    large.push_back(a[i]);
  }
  int it = l;
  for(auto x:smol)
  {
    a[it++] = x;
  }

  for(auto x: med)
  a[it++] = x;

  for(auto x:large)
  a[it++] = x;

  int j1 = l + smol.size() - 1;
  int j2 = j1 + med.size() + 1;
  return std::make_pair(j1,j2);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
//  std::cout << "The current pivot is " << a[k] << std::endl;
  swap(a[l], a[k]);
//  for (auto x: a)
//    cout << x << " ";
  pair <int,int> m = partition2(a, l, r);

  randomized_quick_sort(a, l, m.first );
  randomized_quick_sort(a, m.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

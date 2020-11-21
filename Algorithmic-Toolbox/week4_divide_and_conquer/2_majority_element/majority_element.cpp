#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  std::sort(a.begin(),a.end());

  std::map <int,int> mp;

  for(auto x: a)
  {
    mp[x]++;
  }
  int cc = 0;
  for(auto x : mp)
  {
  //  std::cout << x.second << "\n";
     cc = x.second > cc ? x.second : cc;
  }

//  std:: cout << cc << " " <<  a.size() << std::endl;

  if(cc > a.size()/2)
    return 1;
  else
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

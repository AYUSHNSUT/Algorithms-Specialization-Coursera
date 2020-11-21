#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::queue;
using std::deque;

void InverseBWT(string& bwt) {

  string bw = bwt;
  vector <int> L;

  sort(bwt.begin(),bwt.end());
  map <char, deque <int>> mp;

  int x = 0;int z = 0;
  for(auto c: bw)
  {
    mp[c].push_back(x);
    x++;
    if(c == '$')
      z = x-1;
  }
//  cout << z << endl;
//  cout << bw << endl;
//  cout << bwt << endl;
  for(auto c: bwt)
  {
    int y = mp[c].front();
    L.push_back(y);
    mp[c].pop_front();
  }

  for(int i = 0;i<L.size();i++)
  {
    z = L[z];
    char c = bw[z];
    cout << c ;
  }
  // write your code here

  cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string bwt;
  cin >> bwt;
InverseBWT(bwt) ;
  return 0;
}

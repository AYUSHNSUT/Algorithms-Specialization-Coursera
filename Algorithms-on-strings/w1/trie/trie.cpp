#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {

  int mx = 0;
  for(auto s:patterns)
  {
    mx += s.size();
  }
//  int i = 0;
  trie t(mx);
    int count = 1;
    int prev = 0;
  for(auto p:patterns)
  {
      for(auto c: p)
      {
        if(t[prev][c] == 0)
        {
          t[prev][c] = count;
          prev = count;
          count++;
        }
        else
        {
          prev = t[prev][c];
        }
      }

      prev = 0;

  }
  // write your code here
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}

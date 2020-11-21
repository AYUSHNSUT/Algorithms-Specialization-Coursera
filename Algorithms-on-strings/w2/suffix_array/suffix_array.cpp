#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself

  vector <pair <string, int>> res;
  int n = text.size();
  for(int i = 0;i<text.size();i++)
  {
    res.push_back(make_pair(text.substr(i,n),i));
    n--;
  }

  sort(res.begin(),res.end());

  for(int i = 0;i<res.size();i++)
    result.push_back(res[i].second);
  return result;
}

int main() {

  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}

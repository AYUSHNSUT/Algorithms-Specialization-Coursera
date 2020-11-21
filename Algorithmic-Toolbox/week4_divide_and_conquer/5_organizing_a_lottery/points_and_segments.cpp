#include <iostream>
#include <vector>
#include<set>
#include <algorithm>
#include <map>

using std::vector;
using namespace std;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  map <long long,int> mp;
  vector <pair <int,char>> graf;
  int ctr = 0;
  vector <int> counts(points.size());

  for(auto s:starts)
  {
    graf.push_back(make_pair(s,'A'));
  }
  for(auto e:ends)
  {
    graf.push_back(make_pair(e,'C'));
  }

  for(auto p:points)
  {
    graf.push_back(make_pair(p,'B'));
  }

  sort(graf.begin(),graf.end());

  for(auto g:graf)
  {
    if(g.second == 'A')
      ctr++;
    else if(g.second == 'B')
    {
      mp[g.first] = ctr;
    }
    else
    {
      ctr--;
    }
  }
  int iter = -1;
  for(auto p:points)
  {
    iter++;
    counts[iter] = mp[p];
  }

  return counts;


}
// 1 2 3 4 5
// 0 1 2 3 4

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

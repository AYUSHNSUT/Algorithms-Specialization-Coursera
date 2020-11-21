#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <set>

using std::vector;
using std::pair;
using std::set;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second) ||((a.second) == b.second && a.first < b.first);
}



set<int> optimal_points(vector<pair<int,int>> &segments,int m) {
  set <int> points;
  int point = -1;
    for (auto  segment : segments) {
        if (point < segment.first || point > segment.second) {
            point = segment.second;
            points.insert(point);
        }
    }
    return points;


}

int main() {
  int n;
  std::cin >> n;
  vector<pair<int,int>> segments;
  int maximum = 0;
  int p , q;
  for (size_t i = 0; i < n; ++i) {
  std::cin >> p >> q;
  segments.push_back(std::make_pair(p,q));
  if(q > maximum)
   maximum = q;
  }
  //std::cout << maximum << "\n";
  std::sort(segments.begin(),segments.end(),sortbysec);
  set<int> points = optimal_points(segments,maximum);
  std::cout << points.size() << "\n";
  for (auto z: points) {
    std::cout << z << " ";
  }
}
//27 28 53 54 84

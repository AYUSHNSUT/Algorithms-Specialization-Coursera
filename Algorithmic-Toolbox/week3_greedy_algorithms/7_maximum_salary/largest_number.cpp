#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;

bool crit(string s1,string s2)
{
  return stoi(s1 + s2) < stoi(s2 + s1);
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  sort(a.rbegin(),a.rend(),crit);

  for (auto z : a)
    cout << z;

  string result;
  ret >> result;
  return result;


}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

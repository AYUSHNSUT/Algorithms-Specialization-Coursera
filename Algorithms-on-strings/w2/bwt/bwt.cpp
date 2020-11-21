#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void rotate(string &s)
{
  char tmp = s[s.size()-1];
  for(int i = s.size()-1;i>0;i--)
  {
    s[i] = s[i-1];
  }
  s[0] = tmp;
}

string BWT( string& text) {
  string result = "";

  vector <string> s;

  for(int i = 0;i<text.length();i++)
  {
    s.push_back(text);
    rotate(text);
  }

  sort(s.begin(),s.end());

  for(int i = 0;i<s.size();i++)
  {
    result = result + s[i][text.size()-1];
  }
  // write your code here

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}

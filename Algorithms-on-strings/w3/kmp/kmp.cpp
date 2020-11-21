#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

void make(std::vector<int> &a, const string &s)
{
  int i = 1, check = 0;

  int m = a.size();
  a[0] = 0;
  while(i<m)
  {
    if(s[i] == s[check])
    {
      check++;
      a[i] = check;
      i++;
    }

    else
    {
      if(check == 0)
      {
        a[i] = 0;
        i++;
      }
      else
      {
        check = a[check-1];
      }
    }
  }
}


std::vector<int> KMP(std::vector<int> &lcs, const string &pattern,const  string &text)
{
  int i = 0, j = 0;
  int m = pattern.size();
  int n = text.size();
  std::vector<int> ans;

  while(i < n)
  {
    if(text[i] == pattern[j])
    {
      i++;
      j++;
    }
    if(j == m)
    {
      ans.push_back(i-m);
      j = lcs[j-1];
    }
    else
    {
      if(i < n && text[i]!=pattern[j])
      {
        if(j==0)
        {
          i++;
        }
      else
      {
        j = lcs[j-1];
      }
      }
    }
  }

  return ans;
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  vector <int> LCS(pattern.size());
  make(LCS,pattern);
  result = KMP(LCS,pattern,text);
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}

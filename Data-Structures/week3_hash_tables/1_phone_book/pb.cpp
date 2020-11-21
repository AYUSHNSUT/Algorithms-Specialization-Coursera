#include <bits/stdc++.h>

using namespace std;


int main()
{
  unordered_map <int,string> mp;
  vector <string> ans;
  int n;
  cin >> n;
  for(int i = 0;i<n;i++)
  {
    string s1,s2;
    cin >> s1 >> s2;
    if(s1=="add")
    {
      string s3;
      cin >> s3;
      mp[stoi(s2)] = s3;
    }
    else if(s1 == "find")
    {
      string s = mp[stoi(s2)];
      if(s == "" )
      {
        ans.push_back("not found");
      }
      else
          ans.push_back(s);
    }

    else
    {
      string s = mp[stoi(s2)];
      if(s2=="")
      {

      }
      else
      {
        mp[stoi(s2)] = "";
      }
    }

  }

  for(auto s: ans)
    cout << s << endl;

}

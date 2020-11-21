#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using std::string;
using std::min;

static int dp[101][101];

int edit_distance(const string &str1, const string &str2,int n,int m) {

  if(n==0)
    return m;
  if(m==0)
    return n;

  if(dp[n][m]!=-1)
  {
    return dp[n][m];
  }



    int c1 = edit_distance(str1,str2,n-1,m) + 1; //deletion
    int c2 = edit_distance(str1,str2,n,m-1) + 1; //insertion
    int c3;

    if((str1[n-1] == str2[m-1]))
    {
      c3 = edit_distance(str1,str2,n-1,m-1);
    }
    else
    {
  //    printf("else\n");
      c3 = edit_distance(str1,str2,n-1,m-1) + 1;
    }

//     printf("n = %d, m = %d, c1 = %d\n",n,m,c1);
  //   printf("n = %d, m = %d, c2 = %d\n",n,m,c2);
  //   printf("n = %d, m = %d, c3 = %d\n",n,m,c3);

    int c = min(c1,c2);
    int d = min(c,c3);
    dp[n][m] =  min(c,d);
    return dp[n][m];


}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  int n = str1.size();
  int m = str2.size();

  memset(dp,-1,sizeof(dp));
  dp[0][0] = 0;
  std::cout << edit_distance(str1, str2,n,m) << std::endl;
  return 0;
}

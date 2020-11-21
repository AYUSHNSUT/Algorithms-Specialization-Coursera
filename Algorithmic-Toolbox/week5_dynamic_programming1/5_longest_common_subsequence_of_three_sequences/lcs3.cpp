#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::max;

static int dp[101][101][101];

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c,int n,int m, int p) {
  //write your code here

  if(n==0||m==0||p==0)
    return 0;

  if(dp[n][m][p] != -1)
    return dp[n][m][p];

  if(a[n-1]==b[m-1] &&c[p-1] == a[n-1])
    return dp[n][m][p] =  1 + lcs3(a,b,c,n-1,m-1,p-1);

  else
  {
    int c1 = lcs3(a,b,c,n-1,m,p);
    int c2 = lcs3(a,b,c,n,m-1,p);
    int c12 = max(c1,c2);
    int c3 = lcs3(a,b,c,n,m,p-1);
    dp[n][m][p] = max(c12,c3);
    return dp[n][m][p];
  }
//  return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }

  memset(dp,-1,sizeof(dp));
  std::cout << lcs3(a, b, c,an,bn,cn) << std::endl;
}

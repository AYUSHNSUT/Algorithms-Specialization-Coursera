#include <iostream>
#include <vector>
#include <cstring>

using std::vector;

static int dp[101][101];

int lcs2(vector<int> &a, vector<int> &b,int n,int m) {
  //write your code here

  if(n==0 || m==0)
    return 0;

    if(dp[n][m]!=-1)
      return dp[n][m];

  if(a[n-1] == b[m-1])
    return lcs2(a,b,n-1,m-1) + 1;

  else
  {
    int c1 = lcs2(a,b,n-1,m);
    int c2 = lcs2(a,b,n,m-1);

    return dp[n][m] = std::max(c1,c2);
  }

//  return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  memset(dp,-1,sizeof(dp));

  std::cout << lcs2(a, b,n,m) << std::endl;
}

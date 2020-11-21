#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::max;

static int dp[10001][301];

int optimal_weight(int W, const vector<int> &w,int n) {
  //write your code here

  if(W==0||n==0)
    return 0;

    if(dp[W][n] != -1)
      return dp[W][n];


  if(w[n-1]<=W)
  {
    dp[W][n] = max(optimal_weight(W-w[n-1],w,n-1) + w[n-1] ,  optimal_weight(W, w,n-1 ));
    return dp[W][n];
  }
  else
  {
    dp[W][n] = optimal_weight(W, w,n-1 );
    return dp[W][n];
  }
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  memset(dp,-1,sizeof(dp));
  std::cout << optimal_weight(W, w,n) << '\n';
}

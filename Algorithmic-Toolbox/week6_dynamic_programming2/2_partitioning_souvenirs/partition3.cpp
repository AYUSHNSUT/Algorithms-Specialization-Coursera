#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::max;

static int dp[601][601][30];

int partition3(vector<int> &A,int n,int x,int y) {
  //write your code here
  if(n==0 &&(x!=0 || y!=0) )
    {
      dp[x][y][n] = 0;
      return dp[x][y][n];
    }

  if(x==0 && y==0)
    {
      dp[x][y][n] = 1;
      return dp[x][y][n];
    }

  if(dp[x][y][n]!=-1)
  {
    return dp[x][y][n];
  }

  if(A[n-1] <= x && A[n-1] <= y)
  {
    int c1 = max(partition3(A,n-1,x-A[n-1],y), partition3(A,n-1,x,y-A[n-1]));
    int c2 = partition3(A,n-1,x,y);
    dp[x][y][n] = max(c1,c2);

    return dp[x][y][n];
  }
  else if(A[n-1] <= x)
  {
    dp[x][y][n] = max(partition3(A,n-1,x-A[n-1],y) , partition3(A,n-1,x,y)   );
    return dp[x][y][n];
  }

  else if(A[n-1] <= y)
  {
      dp[x][y][n] =  max(partition3(A,n-1,x,y- A[n-1]) , partition3(A,n-1,x,y)   );
      return dp[x][y][n];
  }

  else
  {
    dp[x][y][n] = partition3(A,n-1,x,y);
    return dp[x][y][n];
  }

}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  int s = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    s += A[i];
  }
  memset(dp,-1,sizeof(dp));

  if(s%3!=0)
    std::cout << 0 << std::endl;


  else
  std::cout << partition3(A,n,s/3,s/3) << '\n';
}

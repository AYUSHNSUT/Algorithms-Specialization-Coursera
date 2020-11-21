#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;
using std::min;


int dp[1000000];

int optimal_sequence(int n ) {
  int a[3];
//  printf("n %d\n",n);
    if(n==1)
      return 0;

    a[0] = n%3 == 0? dp[n/3] != -1 ? (dp[n/3] + 1) : (optimal_sequence(n/3) + 1) :  1e7;
    a[1] = n%2 == 0? dp[n/2] != -1 ? (dp[n/2] + 1 ):  (optimal_sequence(n/2) + 1):  1e7;
    a[2] = dp[n-1] != -1 ?( dp[n-1] + 1) : (optimal_sequence(n - 1)) + 1;

    int m = min(a[0],a[1]);
    return min(m,a[2]);

}

vector <int> travel(int n)
{
  vector <int> s;

  while(n)
  {
    s.push_back(n);
    int c1 = (n%3==0) ? dp[n/3] : 1e9;
    int c2 = (n%2==0) ? dp[n/2] : 1e9;
    int c3 = dp[n-1];

    if(c1 < c2 && c1 < c3)
    {
      n = n /3;
    }
    else if (c2 < c1 && c2 < c3)
    {
      n = n/2;
    }
    else
      n--;
  }

  return s;
}

int main() {
  int n;
  std::cin >> n;

  memset(dp,-1,sizeof(dp));
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
//  sequence.push_back(n);

  for(int i = 4;i<=n;i++)
  {
    dp[i] = optimal_sequence(i);
  }

  vector <int> sequence;

  sequence = travel(n);
  cout << dp[n] << endl;

  reverse(sequence.begin(),sequence.end());

  for(auto s: sequence)
    cout << s <<" ";
  // sequence.push_back( n);
  // if(n!=1)
  // sequence.insert(sequence.begin(),1);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
}
//  for(int i = 0;i<5;i++)
//    printf("dp[i] for i = %d is %d\n", i , dp[i]);

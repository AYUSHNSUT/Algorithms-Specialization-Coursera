#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using namespace std;

// vector<int> optimal_summands(int n) {
//   vector<int> summands;
//   //write your code here
//   return summands;
// }

int main() {
  long long n;
  std::cin >> n;
  // vector<int> summands = optimal_summands(n);
  // std::cout << summands.size() << '\n';
  // for (size_t i = 0; i < summands.size(); ++i) {
  //   std::cout << summands[i] << ' ';
  // }

  double ck = -0.5 + sqrt(1 + 8*n)/2;

  if(abs(ck-int(ck))<1e-6)
  {
    cout << long(ck) <<endl;
    for(long long i = 1;i<=long(ck);i++)
    {
      cout << i <<" ";
    }
  }
  else
  {
    cout << long(ck) <<endl;
    long long s = 0;
    for(long long i = 1;i<long(ck);i++)
    {
      cout << i <<" ";
      s+= i;
    }
    cout << n-s;
  }
}

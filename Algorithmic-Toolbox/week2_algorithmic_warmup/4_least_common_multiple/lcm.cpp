#include <bits/stdc++.h>
using namespace std;

long long gcd_naive(long long a, long long b) {
  if(b==0)
    return a;
  else
    return gcd_naive(b,a%b);
}

long long lcm_naive(long long a, long long b) {
  long long prod = a * b;

  return (a*b) / gcd_naive(a,b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  if(a<b)
  swap(a,b);
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  long n;
  cin >> n;
 vector <long long> a(n);
 for(long long i = 0;i<n;i++)
 cin >> a[i];

sort(a.begin(),a.end());

long long prod = a[n-1] * a[n-2];

cout << prod <<"\n";




}

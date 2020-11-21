#include <iostream>
#include <vector>
using std::vector;

long long pp(long long m)
{
  long long prev = 0;
  long long curr = 1;
  long long per = 0;
  while(true)
  {

    long long c =(prev %m+ curr%m)%m;

    prev = curr;
    curr = c;
    if(prev == 0 && curr == 1)
    return per+1;

        per++;

  }
}


long long get_fibonacci_partial_sum_naive(long long  n,long long m) {
  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < n - 1; ++i) {
      long long tmp_previous = previous ;
      previous = current ;
      current = tmp_previous % m + current % m;
      current = current%m;
  }

  return current % m;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    long long per = pp(10);
    from = from + 1;
    from = from % per;
    to = to + 2;
    to = to % per;
    int ans =  (get_fibonacci_partial_sum_naive(to,10) - get_fibonacci_partial_sum_naive(from,10)) % 10;

    if(ans < 0)
      ans += 10;
    std::cout << ans << '\n';
}

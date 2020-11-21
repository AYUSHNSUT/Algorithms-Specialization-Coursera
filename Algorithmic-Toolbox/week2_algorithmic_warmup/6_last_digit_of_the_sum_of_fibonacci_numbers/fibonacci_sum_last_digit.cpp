#include <iostream>


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



long long get_fibonacci_huge_naive(long long n, long long m) {


    if (n <= 1)
        return n;

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
    long long n;
    std::cin >> n ;
    long long per = pp(10);
    n = (n+2) % per;
    std::cout << (get_fibonacci_huge_naive(n,100) - 1)%10 << '\n';
}

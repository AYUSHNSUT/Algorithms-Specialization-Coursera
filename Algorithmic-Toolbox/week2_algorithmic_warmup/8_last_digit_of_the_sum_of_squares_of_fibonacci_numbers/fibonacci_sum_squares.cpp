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

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous % 10;
        previous = current % 10;
        current = tmp_previous + current;

    }

    return current % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;


      long long per = pp(10);

      long long m = n+1;
      n = n % per;
      m = m%per;

    std::cout << (fibonacci_sum_squares_naive(m)* fibonacci_sum_squares_naive(n))%10;
}

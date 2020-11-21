#include <iostream>
#define ll long long

ll get_fibonacci_last_digit_naive(ll n) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;

    for ( ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous%10;
        previous = current%10;
        current = tmp_previous + current;
        current = current%10;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }

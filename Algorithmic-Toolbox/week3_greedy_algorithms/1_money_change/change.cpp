#include <iostream>

int get_change(int m) {
  //write your code here
  int c1 = m/10;
  m = m %10;
  int c2 = m/5;
  m = m%5;
  int c3 = m;
  return c1+c2+c3;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

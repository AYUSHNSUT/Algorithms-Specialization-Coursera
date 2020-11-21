#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x,int left,int right) {


  while(left < right)
  {
    int mid = left + right;
    mid = mid/2;
  //  std::cout << mid << "\nhjkfdhsf\n";
    if(a[mid]== x)
      return mid;
    else if (a[mid] > x)
    {
      return binary_search(a,x,left,mid);
    }

    else
      return binary_search(a,x,mid+1,right);
  }
  //write your code here
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    int left = 0, right = (int)a.size();
    std::cout << binary_search(a,b[i],left,right) << ' ';
  }
}

#include <iostream>
#include <vector>

using std::vector;

long long merge(vector <int> &a,vector <int>b,int  left,int ave, int right)
{
  int leftStop = ave;
  int rightStart = ave+1;
  int k = left,z = left;
  int x = 0;


  while(left<= leftStop && rightStart <= right)
  {
    if(a[left] <= a[rightStart])
    {
      b[k++] = a[left++];
    }
    else
    {
      b[k++] =a[rightStart++];
      x+= leftStop - left + 1;

    }
  }

  while(left<=leftStop)
  {
    b[k++] = a[left++];
  }
  while(rightStart<=right)
  {
    b[k++] = a[rightStart++];
      x+= leftStop - left + 1;
  }

  for(int i = z;i<=right;i++)
    a[i] = b[i];
  return x;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;


  if (right <= left ) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += merge(a,b,left,ave,right);
  // //write your code here
  // for(auto x : a)
  // {
  //   std::cout << x << " ";
  // }
  // std::cout << "**************\n";
   return number_of_inversions;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}

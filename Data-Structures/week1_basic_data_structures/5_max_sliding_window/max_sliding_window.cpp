#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window_naive(vector<int> const & A, int w) {

    deque <int> D;
    for(int i = 0;i<A.size();i++)
    {
      if(D.empty())
      {
        D.push_back(i);
      }

      while(!D.empty()&&A[i]>=A[D.back()])
      {
        D.pop_back();
      }
      D.push_back(i);


      if(i>=w-1)
      {

        if(i-w == D.front())
            D.pop_front();
        cout << A[D.front()] << " ";



      }

      // printf("Iter %d\n", i);
      // for(auto d:D)
      // {
      //   cout << A[d] << " ";
      // }
      // printf("\n********************************\n");


    }
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}

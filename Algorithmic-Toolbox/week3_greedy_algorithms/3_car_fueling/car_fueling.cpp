#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    // for(auto x: stops)
    //   cout << x << " ";
    //
    //   cout << "\n";

    stops.push_back(dist);

    // for(auto x: stops)
    //   cout << x << " ";
    //
    //   cout << "\n";

    if(stops[0] >tank)
      return -1;

    for(int i = 1;i<stops.size();i++)
    {
      if(stops[i] - stops[i-1] > tank)
        return -1;
    }

    // vector <binary> c(stops.size());
    stops.insert(stops.begin(),0);

    // for(auto x: stops)
    //   cout << x << " ";
    //
    //   cout << "\n";

    auto stop1 = stops.begin(); auto stop2 = stops.begin();
//    stops.push_front(0);
    int steps = 0;

    while(stop2 != stops.end()-1)
    {
  //    cout << *stop2 << " " << *stop1 << "\n";

        while(*stop2 - *stop1 <= tank && stop2!=stops.end())
        {
        //  cout << *stop2 << "\n";
          stop2++;
        }

      //  cout << "        ********8888888  \n";
        stop2--;
    //  cout << *stop2 << "\n";
        if(stop2!=stops.end()-1)
        steps++;
        stop1 = stop2;

    }

    return steps;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

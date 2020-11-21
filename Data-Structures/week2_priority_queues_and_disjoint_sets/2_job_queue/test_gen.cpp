#include <bits/stdc++.h>
using namespace std;

int main()
{
  ofstream fout;
  fout.open("tst.txt");

  fout << 9921 <<" " << 6;
  fout << endl;

  std::random_device rd;

  /* Random number generator */
  std::default_random_engine generator(rd());

  /* Distribution on which to apply the generator */
  std::uniform_int_distribution<long long unsigned> distribution(0,1e9);

  for(int i = 0;i<6;i++)
  {
      fout << distribution(generator) << " ";
  }
  fout << endl;
  fout.close();
  return 0;
}

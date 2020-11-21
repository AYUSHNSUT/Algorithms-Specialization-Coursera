#include <iostream>
#include <cstring>

using namespace std;
int gc[1000];



int get_change(int m) {
  if(gc[m] != -1)
    return gc[m];


  int c1 = gc[m-1] == -1? get_change(m-1) + 1 : gc[m-1] + 1;
  int c2 = gc[m-3] == -1? get_change(m-3) + 1 : gc[m-3] + 1;
  int c3 = gc[m-4] == -1? get_change(m-4) + 1 : gc[m-4] + 1;

  gc[m] = min(c1,c2);
  gc[m] = min(gc[m],c3);
  return gc[m];

}

int main() {
  int m;
  std::cin >> m;
  memset(gc,-1,sizeof(gc));
  gc[0] = 0;
  gc[1] = 1;
  gc[2] = 2;
  gc[3] = 1;
  gc[4] = 1;
  //
  // for(int i = 0;i<100;i++)
  //   cout << i << " " << gc[i] << endl;

  std::cout << get_change(m) << '\n';
}

#include <bits/stdc++.h>
using namespace std;

int height(int k, vector <int> &a, int h[])
{
  if(a[k]==-1)
  {
    h[k]= 1;
    return 1;
  }

  if(h[k]!= -1)
    return h[k];

  h[k] = 1 + height(a[k],a,h);
  return h[k];
}


int main()
{
  int n;
  cin >> n;

  vector <int> a(n);
  int prnt;
  for(int i = 0;i<n;i++)
  {
    cin >> a[i];
    if(a[i]== -1)
      prnt = a[i];
  }

  int mx = -1;

  int h[n];

  memset(h,-1,sizeof(h));

  for(int i = 0;i<n;i++)
  {
    int hm = height(i,a,h);
    if(hm > mx)
    {
      mx = hm;
    }
  }

  for(int i = 0;i<n;i++)
  {
    printf("%d ",h[i]);
  }
  cout << endl;

  cout << mx << endl;
}

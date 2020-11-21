#include<bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define all(c) c.begin(),c.end()

#define M 1000000007


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define mp make_pair
#define pb push_back

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

void dfsEuler(vvi G, int start,map <pii, int>edgeDone){
  for( auto g: G[start]){
    if(!edgeDone[mp(start,g)]){
      edgeDone[mp(start,g)] = 1;
    }
  }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    vvi G(n);
    map <int,,int> indegree;
    map <int,int> outdegree;

    mao <pair <int,int>, int> edgeDone;

    for(int i = 0;i<m;i++){
      int x,y;
      cin >> x >> y;
      G[x-1].pb(y-1);
      indegree[y-1]++;
      outdegree[x-1]++;
    }

    bool flag = true;
    REP(i,n){
      if(indegree[i] != outdegree[i]){
        flag = false;
        break;
      }
    }

    if(flag){
      cout << 1<< endl;
    }
    else
    {
      cout << 1 << endl;
      return 0;
    }

    int start = 0;
    dfsEuler(G, start);



//fout.close();
//fin.close();
    return 0;
}

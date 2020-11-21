#include <iostream>
#include <vector>

typedef unsigned long long ull;
using namespace std;
int x = 99;
ull p1 = 1e9 + 7;
ull p2 = 1e9 + 9;
#define debug(x) cout << '>' << #x << ':' << x << endl;




inline long long fast_mod(const long long x, const long long y) {
    if (x >= y) {
        return x % y;
    } else if (x < 0) {
        return (x % y + y) % y;
    } else {
        return x;
    }
}


ull pow(int A, int B, int C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    ull y;
    if (B % 2 == 0) {
        y = pow(A, B / 2, C);
        y = fast_mod(y*y,C);
    }

    // If B is odd
    else {
        y = fast_mod(A,C);
        y = (y * pow(A, B - 1, C) % C) % C;
    }

    return (ull)((y + C) % C);
}


class Solver {
	string s;
	vector <ull> hash1;
	vector <ull> hash2;
public:
	Solver(string s) : s(s) {
		// initialization, precalculation
		hash1.resize(s.size()+1);
		hash2.resize(s.size()+1);
		hash1[0] = 0;
		hash2[0] = 0;
		for(int i = 1;i<=s.size();i++)
		{
			int k;
      hash2[i] = fast_mod(x * hash2[i-1] + (s[i-1] - 'a'),p2);
			hash1[i] = fast_mod(x * hash1[i-1] + (s[i-1] - 'a'),p1);

		}

		// for(int i = 0;i<=s.size();i++)
		// {
		// 	if(i!=s.size())
		// 	debug(s[i] - 'a');
		// 	debug(hash1[i]);
		// 	debug(hash2[i]);
		// }
	}
	bool ask(int a, int b, int l) {
		ull ha1 = fast_mod(hash1[a+l] - ((pow(x,l,p1) * hash1[a]%p1))%p1,p1);
		ull hb1 =  fast_mod(hash1[b+l] - ((pow(x,l,p1) * hash1[b]%p1))%p1,p1);
			ull ha2 = fast_mod(hash2[a+l] - ((pow(x,l,p2) * hash2[a]%p2))%p2,p2);
		ull hb2 = fast_mod(hash2[b+l] - ((pow(x,l,p2) * hash2[b]%p2))%p2,p2);

	//	debug(h1);
		//debug(h2);

		return (ha1%p1 == hb1%p1) && ha2%p2 == hb2%p2 ;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}

//*(hash1._M_impl._M_start)@8

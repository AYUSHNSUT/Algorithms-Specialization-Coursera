#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
typedef unsigned long long ull;
 ull p1 = 1e9 + 7;
 ull p2 = 1e9 + 9;
int X =  2;

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


ull pow(ull  A,ull  B, ull C)
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

void precompute_hashes(vector <ull> &hash1, vector <ull> &hash2,string s)
{
	int sizee = s.size();
	hash1[0] = 0;
	hash2[0] = 0;
	for(int i = 1;i<=sizee;i++)
	{
    int kimi;
    hash2[i] = fast_mod(X * hash2[i-1] + (s[i-1] - 'a'),p2);
    hash1[i] = fast_mod(X * hash1[i-1] + (s[i-1] - 'a'),p1);
		 // debug(i);
		 //  debug(hash1[i]);
		 //  debug(hash2[i]);

	}
}


struct Answer {
	size_t i, j, len;
};


bool solve_k(int k,string s, string t, vector <ull> &hsp1,vector <ull> &hsp2,vector <ull> &htp1,vector <ull> &htp2,Answer &ans)
{
	map <ull,ull> mp1,mp2;
	for(int i = 1;i<=hsp1.size()-k;i++)
	{
		ull sp1 = fast_mod(hsp1[i+k] - ((pow(X,k,p1) * hsp1[i]%p1))%p1,p1);
		ull sp2 = fast_mod(hsp2[i+k] - ((pow(X,k,p2) * hsp2[i]%p2))%p2,p2);
	//	debug(i);
	//	debug(sp1);
	//	debug(sp2);

	// if(k==5 && i==3)
	// {
	// 	debug(i);
	// 	debug(hsp1[i+k])
	// 	debug(pow(X,k,p1))
	// 	debug(hsp1[i]);
	// 	debug(hsp1[i+k] - pow(X,k,p1) * hsp1[i]);
	// 	debug(sp1);
	// 	debug(sp2);
	// }

		mp1[sp1] = i;
		mp2[sp2] = i;

	}

	// for(auto m:mp)
	// 	cout << m.first <<" " << m.second<< " ";
	// cout << endl;
//	bool tmp = false;
	for(int i = 1;i<=htp1.size()-k;i++)
	{


    ull tp1 = fast_mod(htp1[i+k] - ((pow(X,k ,p1) * htp1[i]%p1))%p1,p1);
		ull tp2 = fast_mod(htp2[i+k] - ((pow(X,k ,p2) * htp2[i]%p2))%p2,p2);
		// if(k==5 && i==1)
		// {
		// 	debug(i);
		// 	debug(htp1[i+k])
		// 	debug(pow(X,k,p2))
		// 	debug(htp1[i]);
		// 	debug(htp1[i+k] - pow(X,k,p2) * htp1[i]);
    //
		// 	debug(tp1);
		// 	debug(tp2);
		// }

		bool tmp = ((mp1[tp1]!=0) && (mp2[tp2]!=0));// || ((tp1 > 1e5) &&((mp1[tp1-1]) && mp2[tp2-1]));
		if(tmp)
		{
			if(ans.len <k)
			{
			ans.i = mp1[tp1];
			ans.j = i;
			ans.len = k;
			}
			return true;
		}
	}

	return false;
}

Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	vector <ull> hash1p1(s.size()+1), hash1p2(s.size()+1);
	vector <ull> hash2p1(t.size()+1), hash2p2(t.size()+1);
	precompute_hashes(hash1p1,hash1p2,s);
	precompute_hashes(hash2p1,hash2p2,t);

	// for(int i = 0;i<s.size();i++)
	// {
	// 	debug(hash1p1[i]);
	// 	debug(hash1p2[i]);
	// }
	//
	// for(int i = 0;i<s.size();i++)
	// {
	// 	debug(hash2p1[i]);
	// 	debug(hash2p2[i]);
	// }

	//unordered_map <int,int> mp;
	// debug(s.size());
	// debug(t.size());
	int check = std::min(s.size(),t.size());
	int left = 0;
	int right = check + 1;

//	debug(left);
	//debug(right);
	//int mx = 0;
	while(left<=right)
	{
		int mid = (left+right)/2;

		// if(mid == 4)
		// {
		// 	debug(mid);
		// }
	//	 debug(mid);
		bool k = solve_k(mid,s,t,hash1p1,hash1p2,hash2p1,hash2p2,ans);
	//	debug(k);
		if(k)
		{
			left = mid+1 ;
		}

		else
		{
			right = mid-1;
		}

	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	Answer ans = {0,0,0};
	while (cin >> s >> t) {
		if(!s.empty()&&!t.empty())
		 ans = solve(s, t);
		 else
		 break;
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}


/*

for (size_t i = 0; i < s.size(); i++)
	for (size_t j = 0; j < t.size(); j++)
		for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
			if (len > ans.len && s.substr(i, len) == t.substr(j, len))
				ans = {i, j, len};

				voteforthegreatalbaniaforyou choosethegreatalbanianfuture
*/

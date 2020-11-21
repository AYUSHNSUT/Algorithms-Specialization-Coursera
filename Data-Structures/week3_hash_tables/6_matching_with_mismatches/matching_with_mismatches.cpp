#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int multiplier = 31;
ull p1 = 1000000007;
ull p2 = 1000000009;

void prefix(vector<ull>&h,string s,ull m)
{
	h[0] = 0;
	for(int i = i;i<h.size();i++)
	{
		h[i] = (h[i-1] * multiplier + s[i]) %m;
	}
}

vector<int> solve(int k, const string &text, const string &pattern) {
	vector<int> pos;
	vector <ull> ht1(text.size()+1);
		vector <ull> hp1(pattern.size()+1);
			vector <ull> ht2(text.size()+1);
				vector <ull> hp2(pattern.size()+1);

		prefix(ht1,text,p1);
		prefix(ht2,text,p2);
		prefix(hp1,pattern,p1);
		prefix(hp2,pattern,p2);

		int low = 0;
		int high = pattern.size();

		int i = 0;

		while(i < pattern.size())
		{
			int mid = (high + low)/2;
			ull h1 = compute_hash_substring(i,ht1)
		}

	return pos;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;
	while (cin >> k >> t >> p) {
		auto a = solve(k, t, p);
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    5;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: //cout << letter;
		assert (false); return -1;
	}
}

std::vector<int> match(vector <Node> &data, string s)
{
	vector <int> ans;
//	int curr =  0;
	for(int i = 0;i<s.length();i++)
	{

			if(data[0].next[letterToIndex(s[i])] != -1)
			{
				int j = i+1;
				int curr = data[0].next[letterToIndex(s[i])];
				do
				{
				bool f1 = data[curr].next[4] == 69;
					if(data[curr].next[4] == 69)
					{
						ans.push_back(i);
						if( j>= s.size())
						{
							break;
						}
					}

					if(j<s.size() && data[curr].next[letterToIndex(s[j])] != -1)
					{
						curr = data[curr].next[letterToIndex(s[j])];
						j++;
						continue;
					}
					if(j >= s.size()  || (data[curr].next[letterToIndex(s[j])] == -1))
					{
					//		printf("%c\n", s[i]);
						break;
					}
				}while((j==s.size() && data[curr].next[4] == 69 ) || (j<s.length()));
			}
	}
	return ans;
}

void insert(int head,string s,vector <Node> &data)
{
	int curr = head;

	for(auto c: s)
	{
		int index = letterToIndex(c);
		if(data[curr].next[index] == -1)
		{
			data[curr].next[index] = data.size();
			data.push_back(Node());
			curr = data[curr].next[index];
		}
		else
		{
			curr =  data[curr].next[index] ;
		}
	}
	// cout << "********\n";
	// cout << curr << endl;
	data[curr].next[4] = 69;
}



vector <int> solve (string text, int n, vector <string> patterns)
{
	vector <int> result;

	vector <Node> data;
	data.push_back(Node());
	// write your code here
	//cout << "Patterns\n";
	for(auto s: patterns)
	{
		insert(0,s,data);
	}

	// for(auto d:data)
	// {
	// 	cout << d.next[0] << endl;
	// 		cout << d.next[1] << endl;
	// 			cout << d.next[2] << endl;
	// 				cout << d.next[3] << endl;
	// 				cout << d.next[4] << endl;
	// }
	// cout << "Match\n";

	// write your code here
		result = match(data,text);
		sort(result.begin(), result.end());
auto last = unique(result.begin(), result.end());
result.erase(last, result.end());
	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}

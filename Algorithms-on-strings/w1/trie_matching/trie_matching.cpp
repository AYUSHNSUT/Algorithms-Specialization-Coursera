#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}


	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
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
		default: assert (false); return -1;
	}
}


std::vector<int> match(vector <Node> &data, string s)
{
	vector <int> ans;
//	int curr =  0;
	for(int i = 0;i<s.length();i++)
	{
		//	printf("i =%d\n",i);
			if(data[0].next[letterToIndex(s[i])] != -1)
			{
				int j = i;
				int curr = 0;
				while(j<s.length())
				{
				//	printf("next %d\n",data[j].next[letterToIndex(s[j])]);
			//	printf("j = %d\n", j);
					if(data[curr].next[letterToIndex(s[j])] != -1)
					{
				//		printf("j = %d\n",j);
						curr = data[curr].next[letterToIndex(s[j])];
						j++;
					}
			 		if(data[curr].isLeaf())
					{
					//	cout << "psuhin\n";
						ans.push_back(i);
						break;
					}
					if(j >= s.size() || (data[curr].next[letterToIndex(s[j])] == -1 && !data[curr].isLeaf()))
					{
					//		printf("%c\n", s[i]);
						break;

					}
				}
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
}


vector <int> solve (const string& text, int n, const vector <string>& patterns)
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
	// }
	// cout << "Match\n";
	result = match(data,text);
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

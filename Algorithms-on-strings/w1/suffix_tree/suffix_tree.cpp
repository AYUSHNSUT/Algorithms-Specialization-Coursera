#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

struct Node
{
  char c;
  Node* next;
};

class Trie
{
  Node *root;

public:
  Trie()
  {
    root = new Node();
    root-> c = 0;
    root->next = nullptr;
  }


  void Add(string s)
  {
      Node* tmp = root;
      for(int i = 0;i<s.size();i++)
      {
        if(tmp->next->c == 's[i]')
          tmp = tmp->next;

        else
        {
          Node* newn = new Node();
          newn -> c = s[i];
          newn ->next = nullptr;
          tmp ->next = newn;
        }
      }
  }
}


// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding
// substrings of the text) in any order.
vector<string> ComputeSuffixTreeEdges(const string& text) {
  vector<string> result;
  // Implement this function yourself
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}

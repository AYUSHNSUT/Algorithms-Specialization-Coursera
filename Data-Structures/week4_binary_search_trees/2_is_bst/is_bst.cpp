#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

struct Node {
  long key;
  long left;
  long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long key_, long left_, long right_) : key(key_), left(left_), right(right_) {}
};

bool iss(const vector <Node> &tree, long i, long minp, long maxp)
{
    if(i == -1)
      return true;

    if(tree[i].key < minp || tree[i].key > maxp)
      return false;

    return iss(tree, tree[i].left, minp, tree[i].key-1) && iss(tree, tree[i].right, tree[i].key, maxp);
}




bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
    if(tree.empty())
      return true;
    return iss(tree,0,LONG_MIN,LONG_MAX);
}

int main() {
  long nodes;
  cin >> nodes;
  vector<Node> tree;
  for (long i = 0; i < nodes; ++i) {
    long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
/*
14
10 1 2
0 3 4
20 5 6
-5 7 8
5 9 10
15 11 12
20 -1 13
-10 -1 -1
-5 -1 -1
2 -1 -1
5 -1 -1
10 -1 -1
15 -1 -1
25 -1 -1
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

// class Node;
//
// class Node {
// public:
//     int key;
//     Node *parent;
//     std::vector<Node *> children;
//
//     Node() {
//       this->parent = NULL;
//     }
//
//     void setParent(Node *theParent) {
//       parent = theParent;
//       parent->children.push_back(this);
//     }
// };
//


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






int main_with_large_stack_space() {
  // std::ios_base::sync_with_stdio(0);
  // int n;
  // std::cin >> n;
  //
  // std::vector<Node> nodes;
  // nodes.resize(n);
  // for (int child_index = 0; child_index < n; child_index++) {
  //   int parent_index;
  //   std::cin >> parent_index;
  //   if (parent_index >= 0)
  //     nodes[child_index].setParent(&nodes[parent_index]);
  //   nodes[child_index].key = child_index;
  // }

  // // Replace this code with a faster implementation
  // int maxHeight = 0;
  // for (int leaf_index = 0; leaf_index < n; leaf_index++) {
  //   int height = 0;
  //   for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
  //     height++;
  //   maxHeight = std::max(maxHeight, height);
  // }
  //
  // std::cout << maxHeight << std::endl;


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

  // for(int i = 0;i<n;i++)
  // {
  //   printf("%d ",h[i]);
  // }
  // cout << endl;

  cout << mx << endl;



  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

bool validParent(int x,int y)
{
  return x*2+1 < y-1 && x>=0 ;
}
bool validchild(int x,int y)
{
  return x < y && x>=0;
}

bool invarient(vector <int> &a)
{
  for(int i = 0;i<a.size();i++)
  {
    if(validchild(i*2+1,a.size()) && validchild(i*2+2,a.size()))
    {
      if(a[i*2+1]<a[i] || a[i*2+2]<a[i])
        return false;
    }

    if(validchild(i*2+1,a.size()))
    {
      if(a[i*2+1]<a[i] )
        return false;
    }
  }
  return true;
}

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();


  while(!invarient(data_))
  {

    for(int i = 0;i<data_.size();i++)
    {
      int parent = i;
      int child1 = 2*i+1;
      int child2 = 2*i + 2;
      if(validchild(child1,data_.size()) || validchild(child2,data_.size()))
      {
        while( (validchild(child1,data_.size()) || validchild(child2,data_.size()) )&& (data_[parent]>data_[child1]|| (validchild(child2,data_.size())&&data_[parent]>data_[child2])))
        {
            if(validchild(child1,data_.size()) && validchild(child2,data_.size()))
            {
              if(data_[parent]>=data_[child1]&& (data_[parent] <= data_[child2])|| data_[child1] <= data_[child2])
              {
                swap(data_[parent] , data_[child1]);
                swaps_.push_back(make_pair(parent, child1));
                parent = child1;
                child1 = parent* 2 + 1 ;
                child2 = parent*2 + 2 ;
              }

              else if(data_[parent] >= data_[child2])
              {
                swap(data_[parent] , data_[child2]);
                swaps_.push_back(make_pair(parent, child2));
                parent = child2;
                child1 = parent* 2 + 1;
                child2 = parent*2 + 2 ;
              }
            }

            else if(validchild(child1,data_.size()))
            {
              if(data_[parent] > data_[child1])
              {
                swap(data_[parent] , data_[child1]);
                swaps_.push_back(make_pair(parent, child1));
                parent = child1;
                child1 = parent* 2 + 1;
                child2 = parent*2 + 2 ;
              }
            }
        }
      }
    }
  }
  
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}

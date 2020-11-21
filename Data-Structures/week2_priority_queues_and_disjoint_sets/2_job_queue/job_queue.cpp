#include <bits/stdc++.h>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;
using std::make_pair;

using namespace std;

typedef pair <long long,long long> pii;


class myComparator
{
public:
    int operator() (const pii& p1, const pii& p2)
    {
        return p1.first>p2.first || (p1.first == p2.first && p1.second >p2.second);
    }
};

class JobQueue {
 private:
  int num_workers_;
  vector<long long> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
  //  ofstream fout;
  //  fout.open("ans.txt");
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }

//    fout.close();
  }

  void ReadData() {
  //  ifstream fin;
//    fin.open("tst.txt");
    int m;
    cin >> num_workers_ >> m;//c
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];//c
//    fin.close();
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    //vector<long long> next_free_time(num_workers_, 0);
    priority_queue<pii, vector <pii>, myComparator> pq;
    if(num_workers_ < jobs_.size())
    {
      int i = 0;
      for(i = 0;i<num_workers_;i++)
      {
        pq.push(make_pair(jobs_[i],i));
        start_times_[i] = 0;
        assigned_workers_[i] = i;
      }
      for(;i<jobs_.size();i++)
      {
        pii p1 = pq.top();
        assigned_workers_[i] = p1.second;
        start_times_[i] = p1.first;
        pq.pop();
        pq.push(make_pair(start_times_[i] + jobs_[i],assigned_workers_[i]));
      }
    }

    else
    {
      for(int i = 0;i<jobs_.size();i++)
      {
        start_times_[i] = 0;
        assigned_workers_[i] = i;
      }
    }

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}

/*
for (int i = 0; i < jobs_.size(); ++i) {
  int duration = jobs_[i];
  int next_worker = 0;
  for (int j = 0; j < num_workers_; ++j) {
    if (next_free_time[j] < next_free_time[next_worker])
      next_worker = j;
  }
  assigned_workers_[i] = next_worker;
  start_times_[i] = next_free_time[next_worker];
  next_free_time[next_worker] += duration;
}
*/

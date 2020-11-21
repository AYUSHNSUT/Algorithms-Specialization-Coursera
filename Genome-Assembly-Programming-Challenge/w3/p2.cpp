#include <bits/stdc++.h>

using namespace std;



// find the max overlapping between 2 reads with a minimum overlap k
int minOverlap(const string& read1, const string& read2){
    int maxOverlap = -1;
    for(int i = 0;i<read1.size();i++){
        int currOverlap = 0;
        int k = i;

        for(int j=0; j < read2.size();j++){
          if(read1[k++] != read2[j]) break;
          else currOverlap++;
        }


      maxOverlap = max(maxOverlap,currOverlap);
    }

    return maxOverlap;
}



int main(){
  vector <string> reads;
  set <string> uniqq;

  for( int i = 0;i< 400;i++){
    string tmp;
    cin >> tmp;

    uniqq.insert(tmp);
  }

  for(auto x: uniqq){
    reads.push_back(x);
  }

  int mino = INT_MAX;
  for(int i = 0;i<reads.size();i++){
    for(int j = i+1;j<reads.size();j++){
      int k = minOverlap(reads[i],reads[j]);
      mino = min(mino,k);
    }
  }

  cout << mino << endl;

}

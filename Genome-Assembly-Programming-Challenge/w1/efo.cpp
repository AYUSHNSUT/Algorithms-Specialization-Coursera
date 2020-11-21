#include <bits/stdc++.h>

using namespace std;



// find the max overlapping between 2 reads with a minimum overlap k
int findMatchedLength(const string& read1, const string& read2){
    for(int i = 0;i<100;i++){
        int k = i;

        for(int j=0; k < 100; k++, j++)
            if(read1[k] != read2[j]) break;

        if(k == 100)
            return 100 - i;
    }
    return 0;
}

//find max overlap graph where every node represent a read and every node has only one out edge represent the max
// overlap between it and another node
void overLap_graph(const vector<string>& reads, int n, string& genome){
    // set<int> visited;
    // visited.insert(0); // start with read0
    vector <int> visited(n);
    int visCount = 1;
    visited[0] = 1;
    int curRead = 0;
    genome = reads[0];
    int numVis = 1;

    while(numVis != n){
        int molap = 0, othread = -1;

        for(int i = 0;i<n;i++){
            if(visited[i] == 0){
                // max overlap between read1 and read2
                int ovl = findMatchedLength(reads[curRead], reads[i]);

                if(ovl > molap){
                    molap = ovl;     //overlapping length
                    othread = i;         //other read
                }
            }
        }

        // concatenate the current next read with the genome sequence after remove the overlap from it.
        genome += reads[othread].substr(molap, 100 - molap);
        curRead = othread;
        visited[curRead] = 1;  // start from this node now
        numVis++;
    }

    //cut one of overlapping between last and first reads of the genome
    genome = genome.substr(0, genome.size() - findMatchedLength(reads[curRead], reads[0]));

}

int main(){
  vector <string> reads;
  set <string> uniqq;

  for( int i = 0;i< 1618;i++){
    string tmp;
    cin >> tmp;

    uniqq.insert(tmp);
  }

  for(auto x: uniqq){
    reads.push_back(x);
  }

  string genome = "";
  overLap_graph(reads, reads.size(), genome);
  cout << genome << endl;
}

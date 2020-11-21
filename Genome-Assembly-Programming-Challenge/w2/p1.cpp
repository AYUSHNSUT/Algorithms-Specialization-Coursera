#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << std::endl;

#define TOT 25
const int xs = sqrt(TOT);

int row = 0, col = 0;
vector <int> visited(TOT);
map <int,int> mp;
vector <string> tmp;

bool flag = false;

void backtrack(int i, vector<vector <string>> S){

  if(flag){
    return;
  }
  if(i==TOT){
    flag = true;
    for(int b = 0;b<TOT;b++)
    {
      cout << "(";
      vector <string> tmp = S[mp[b]];
      int ctr = 0;
      for(auto n : tmp){
        ctr++;
        cout << n;
        if(ctr == 4){
        }
        else{
          cout << ",";
        }
      }
      cout << ")";
      if((b+1)%xs == 0)
      cout << "\n";
      else
      cout << ";";
    }
  }
  row =  i / xs;
  col = i%xs;
  // debug(i);
  // if(i>0){
  //   debug(mp[i-1]);
  // }
  // debug(row);
  // debug(col);

    if(i == 0){
      int ctr = 0;
      for(int z = 0;z<S.size();z++){
        auto s = S[z];
        if(s[0] == "black" && s[1] == "black"&& visited[z] == 0){
            visited[z]  =1;
            mp[i] = z;
            backtrack(i+1, S);
            visited[z] = 0;
            mp[i] = -1;
        }
      }
    }

      else if(row == 0 && col == xs-1){
      int ctr = 0;
      for(int z = 0;z<S.size();z++){
        auto s = S[z];
        if(s[0] == "black" && s[3] == "black"&& visited[z] == 0){
            visited[z]  =1;
            mp[i] = z;
            backtrack(i+1, S);
            visited[z] = 0;
            mp[i] = -1;
        }
      }
    }

    else if(row == xs-1 && col == xs-1){
    int ctr = 0;

    for(int z = 0;z<S.size();z++){
      auto s = S[z];
      if(s[2] == "black" && s[3] == "black"&& visited[z] == 0){
          visited[z]  =1;
          mp[i] = z;
          // cout << "Done\n";
          backtrack(i+1, S);
          visited[z] = 0;
          mp[i] = -1;
      }
    }
  }

  else if(row == xs-1 && col == 0){
  int ctr = 0;
  for(int z = 0;z<S.size();z++){
    auto s = S[z];
    if(s[1] == "black" && s[2] == "black" && visited[z] == 0){
        visited[z]  =1;
        mp[i] = z;
        backtrack(i+1, S);
        visited[z] = 0;
        mp[i] = -1;
    }
  }
}

else if(row == 0){
  for(int z = 0;z<S.size();z++){
    auto s = S[z];
    if(visited[z] == 0){
        if(s[0] == "black" && S[mp[i-1]][3] == s[1] ){
          visited[z] = 1;
          mp[i] = z;
          backtrack(i+1,S);
          visited[z] = 0;
          mp[i] = -1;
        }
    }
  }
}

else if(col == 0){
  for(int z = 0;z<S.size();z++){
    auto s = S[z];
    if(visited[z] == 0){
        if(s[1] == "black" && S[mp[i-xs]][2] == s[0]){
          visited[z] = 1;
          mp[i] = z;
          backtrack(i+1,S);
          visited[z] = 0;
          mp[i] = -1;
        }
    }
  }
}

else if(col == xs-1){
  for(int z = 0;z<S.size();z++){
    auto s = S[z];
    if(visited[z] == 0){
        if(s[3] == "black" && S[mp[i-xs]][2] == s[0] &&S[mp[i-1]][3] == s[1]){
          visited[z] = 1;
          mp[i] = z;
          backtrack(i+1,S);
          visited[z] = 0;
          mp[i] = -1;
        }
    }
  }
}
else if(row == xs-1){
  for(int z = 0;z<S.size();z++){
    auto s = S[z];
    if(visited[z] == 0){
        if(s[2] == "black" &&S[mp[i-1]][3] == s[1] && S[mp[i-xs]][2] == s[0]){
          visited[z] = 1;
          mp[i] = z;
          backtrack(i+1,S);
          visited[z] = 0;
          mp[i] = -1;
        }
    }
  }
}

else{
  for(int z = 0;z<S.size();z++){
    auto s = S[z];
    // debug(S[mp[i-1]][3]);
    if(visited[z] == 0){
        if(S[mp[i-1]][3] == s[1] && S[mp[i-xs]][2] == s[0]){
          visited[z] = 1;
          mp[i] = z;
          backtrack(i+1,S);
          visited[z] = 0;
          mp[i] = -1;
        }
    }
  }
}


return;


}

int main(){


  vector <vector <string>> S;
  for(int i = 0;i<TOT;i++){
    string tmp;
    cin >> tmp;

    stringstream ss(tmp.substr(1,tmp.size()-2));
    vector <string> tS;
    while(ss.good()){
      string substr;
      getline(ss, substr, ',');

      tS.push_back(substr);
    }
    S.push_back(tS);
  }

  // for(auto x: S){
  //   for(auto y: x){
  //     cout << y << " ";
  //   }
  //   cout << endl;
  // }



  int i = 0;
  backtrack(i,S);


  return 0;
}

/*

(yellow,purple,black,green)
(orange,green,black,purple)
 (black,green,red,black)
 (purple,green,orange,green)
 (green,green,purple,black)
  (black,red,green,green)
  (green,red,red,red)
  (red,red,purple,orange)
   (purple,red,black,black)
    (yellow,green,purple,orange)
     (yellow,black,orange,red)
      (purple,green,yellow,green)
       (red,black,yellow,red)
        (green,purple,yellow,green)
         (orange,orange,green,black)
       (purple,red,red,purple)
          (red,orange,purple,green)
           (red,green,orange,black)
            (orange,black,green,green)
             (orange,purple,black,red)
             (green,black,black,purple)
             (black,yellow,green,orange)
             (purple,green,orange,green)
             (black,black,red,yellow)
            (black,orange,purple,red)

*/

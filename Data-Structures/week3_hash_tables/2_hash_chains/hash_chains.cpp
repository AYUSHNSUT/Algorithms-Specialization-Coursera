#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::deque;
struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<deque <string>>elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
      elems.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if(query.type == "check")
        {
          auto z = elems[query.ind];
          if(z.empty())
          {
            cout << endl;
          }
          else
          {
            for(auto k:z)
            {
              cout << k << " ";

            }
              cout << endl;
          }
        }

        else
        {
          int h = hash_func(query.s);
          if(query.type == "find")
          {
            auto check = elems[h];
            bool flag = false;
            for(auto z: check)
            {
              if(z==query.s)
                {
                  flag = true;
                  break;
                }
            }
            writeSearchResult(flag);
          }


          else if(query.type == "add")
          {
            auto check = elems[h];
            bool flag = false;
            for(auto z: check)
            {
              if(z==query.s)
                {
                  flag = true;
                  break;
                }
            }
            if(flag == false)
            {
              elems[h].push_front(query.s);
            }
          }

          else
          {
            auto check = elems[h];
            int i = 0;
            for(auto z: check)
            {
              if(z==query.s)
                {
                  // cout << "DELETING\n";
                  // cout << "i = " << i << endl;
                  // auto t = check.begin();
                  // cout << *(t + i) << endl;
                  elems[h].erase(elems[h].begin()+i);
                  break;
                }

              i++;
            }
          }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}


/*
if (query.type == "check") {
    // use reverse order, because we append strings to the end
    for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
        if (hash_func(elems[i]) == query.ind)
            std::cout << elems[i] << " ";
    std::cout << "\n";
} else {
    vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
    if (query.type == "find")
        writeSearchResult(it != elems.end());
    else if (query.type == "add") {
        if (it == elems.end())
            elems.push_back(query.s);
    } else if (query.type == "del") {
        if (it != elems.end())
            elems.erase(it);
    }
}
*/

/*
#include <iostream>
#include <string>
#include <vector>
//#include <cmath>

#define debug(x) cout << '>' << #x << ':' << x << endl;
using std::string;
using std::cout;
using std::endl;
typedef unsigned long long ull;


ull pow(int A, int B, int C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    ull y;
    if (B % 2 == 0) {
        y = pow(A, B / 2, C);
        y = (y * y) % C;
    }

    // If B is odd
    else {
        y = A % C;
        y = (y * pow(A, B - 1, C) % C) % C;
    }

    return (ull)((y + C) % C);
}

ull hash_func(string s)
{
  ull h = 0;
  ull p = 1e9 + 7;
  ull d = 10;
  for(int i = s.size()-1;i>=0;i--)
  {
      //debug(s[i] - 'A');
    //  cout << s[i] << endl;
    //  debug(pow(d,s.size()-i,p));
      h = (h%p + ((s[i] - 'A') * pow(d,s.size()-i-1,p)))%p;
  }
//  cout << "h " << h << endl;
  return h;

}

ull edit_hash(ull z,string s, char old, char news)
{
  ull p = 1e9+7;
  ull d = 10;
//  debug(old);
//  debug(news);
  //debug(z%p);
//  debug(old- 'A');
//  debug(pow(d,s.size()-1,p));
//  debug(((old - 'A' ) * pow(d,s.size()-1,p)));
  //debug(((z%p - ((ull)(old ) * (ull)pow(d,s.size()-1))%p) * d) %p);


  //cout << " original z " << z << endl;
  ull oldie = (old-'A')%p;

  ull remover = (oldie * pow(d,s.size()-1,p))%p;

  z = ( (z- remover) % p * d%p) % p;

//  debug(z);

  ull adder = (news - 'A');
  z = (z%p + adder%p)%p;
  return z;
}

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;

    string s1 = t.substr(0,s.size());
    ull x = hash_func(s1);
    ull y = hash_func(s);
    if(x==y && s1==s)
      ans.push_back(0);

    for(int i = 1;i<=t.size()-s.size();i++)
    {
      x = edit_hash(x,s,t[i - 1],t[i+s.size()-1]);
      if(x==y && s == t.substr(i,s.size()))
      {
        ans.push_back(i);
      }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}

/*
for (size_t i = 0; i + s.size() <= t.size(); ++i)
    if (t.substr(i, s.size()) == s)
        ans.push_back(i);
*/

*/

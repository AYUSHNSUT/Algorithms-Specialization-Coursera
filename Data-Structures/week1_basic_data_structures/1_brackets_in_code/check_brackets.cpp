#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::cout;
using std::endl;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    stack <Bracket> s;
    bool one = true;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b1 = Bracket(next,position+1);
            s.push(b1);
        }

        if (next == '}' || next == ']' || next == ')') {
            // Process closing bracket, write your code here
            if( s.empty()|| !s.top().Matchc(next))
            {
          //    cout << "hey";
              one = false;
              cout << position + 1 << endl;
              break;
            }
            else
            {

                s.pop();
            }
        }
    }

    if(one)
    {
      if(s.empty())
      {
        cout << "Success\n";
      }
      else
      {
        cout << s.top().position;
      }
    }

    // Printing answer, write your code here

    return 0;
}

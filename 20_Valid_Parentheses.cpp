#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      vector<char> leftParentheses;
      vector<char> rightParentheses;
      leftParentheses.push_back('(');
      leftParentheses.push_back('{');
      leftParentheses.push_back('[');
      rightParentheses.push_back(')');
      rightParentheses.push_back('}');
      rightParentheses.push_back(']');
      stack<char> stk;
      for(int i=0; i<s.size(); ++i){
        char c = s[i];
        vector<char>::iterator it;
        it = find(leftParentheses.begin(), leftParentheses.end(), c);
        if(it != leftParentheses.end()){
          stk.push(c);
        }
        it = find(rightParentheses.begin(), rightParentheses.end(), c);
        if(it != rightParentheses.end()){
          if(stk.empty()){
            return false;
          }
          else{
            char lastParenthesis = stk.top();
            stk.pop();
            if(leftParentheses[it-rightParentheses.begin()]!=lastParenthesis){
              return false;
            }
          }
        }
      }
      if(stk.empty()){
        return true;
      }
      else{
        return false;
      }
    }
};

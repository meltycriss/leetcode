#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool repeatedSubstringPattern(string str) {
      for(int i=0; i<str.size()/2; ++i){
        if(str.size() % (i+1) > 0) continue;
        bool canFinish = true;
        for(int j=i+1; j<str.size(); ++j){
          if(str[j]!=str[j%(i+1)]){
            canFinish = false;
            break;
          }
        }
        if(canFinish) return true;
      }
      return false;
    }
};

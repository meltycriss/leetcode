#include <math>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      int l=0, r=s.size()-1;
      while(l<r){
        while(l<r && !isValid(s[l])){
          ++l;
        }
        while(l<r && !isValid(s[r])){
          --r;
        }
        if(!isEqui(s[l], s[r])){
          return false;
        }
        ++l;
        --r;
      }
      return true;
    }

    bool isValid(char c){
      return (c>='0' && c<='9') || (toupper(c)>='A' && toupper(c)<='Z');
    }

    bool isEqui(char lhs, char rhs){
      return toupper(lhs)==toupper(rhs);
    }
};

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      string res = "";
      int c = 0, l = a.size()-1, r = b.size()-1;
      while(l>=0 || r>=0 || c==1){
        c += l>=0 ? a[l--]-'0' : 0;
        c += r>=0 ? b[r--]-'0' : 0;
        res = char(c % 2 + '0') + res;
        c /= 2;
      }
      return res;
    }

//    string addBinary(string a, string b) {
//      int l = a.size()-1;
//      int r = b.size()-1;
//      string res;
//      res.resize(max(l,r)+1);
//      int pt = res.size()-1;
//      bool carry = false;
//      for(;l!=0 && r!=0; --l,--r,--pt){
//        char lhs = a[l];
//        char rhs = b[r];
//        if(carry){
//          res[pt] = (lhs-'0') ^ (rhs-'0') ^ 1;
//          carry = (lhs-'0') | (rhs-'0');
//        }
//        else{
//          res[pt] = (lhs-'0') ^ (rhs-'0');
//          carry = (lhs-'0') & (rhs-'0');
//        }
//      }
//      if(l!=0){
//        for(; l>=0; --l){
//          res[l] = a[l];
//        }
//      }
//      else{
//        for(; r>=0; --r){
//          res[r] = b[r];
//        }
//
//      }
//      return res;
//    }
};



int main(){
  cout << Solution().addBinary("11", "1") << endl;
  return 0;
}

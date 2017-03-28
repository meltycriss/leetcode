#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      bool res = true;
      vector<int> ptnS(256, 0);
      vector<int> ptnT(256, 0);
      for(int i=0; i<s.size(); ++i){
        char cS = s[i], cT = t[i];
        if(ptnS[cS]!=ptnT[cT]){
          return false;
        }
        ptnS[cS] = i+1;
        ptnT[cT] = i+1;
      }
      return res;
    }

//    bool isIsomorphic(string s, string t) {
//      bool res = true;
//      map<char, char> mp;
//      vector<bool> charTaken(256, false);
//      for(int i=0; i<s.size(); ++i){
//        char cS = s[i];
//        char cT = t[i];
//        if(mp.count(cS)==0){
//          if(!charTaken[cT]){
//            charTaken[cT] = true;
//            mp[cS] = cT;
//          }
//          else{
//            return false;
//          }
//        }
//        else{
//          if(mp[cS]!=cT){
//            return false;
//          }
//        }
//      }
//      return res;
//    }
};

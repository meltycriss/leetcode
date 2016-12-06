#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
      map<char, int> mp;
      for(int i=0; i<s.size(); ++i){
        char c = s[i];
        if(mp.find(c)==mp.end()){
          mp[c] = 1;
        }
        else{
          ++mp[c];
        }
      }
      for(int i=0; i<s.size(); ++i){
        char c = s[i];
        if(mp[c] == 1) return i;
      }
      return -1;
    }
};

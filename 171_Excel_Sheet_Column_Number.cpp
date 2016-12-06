#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int BASE = 26;
    int titleToNumber(string s) {
      int res = 0;
      for(int i=0; i<s.size(); ++i){
        res *= BASE;
        res += s[i] - 'A';
        ++res;
      }
      return res;
    }
};


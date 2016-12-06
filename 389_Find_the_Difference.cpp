#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
//      sort(s.begin(), s.end());
//      sort(t.begin(), t.end());
//      int idx = 0;
//      while(idx<min(s.size(), t.size()) & s[idx]==t[idx]){
//        ++idx;
//      }
//      char res = (s.size()>t.size())? s[idx]:t[idx];
//      return res;
//    }

    char res = 0;
    for(int i=0; i<s.size(); ++i) res ^= s[i];
    for(int i=0; i<t.size(); ++i) res ^= t[i];
    return res;
    }
};

int main(){
  cout << Solution().findTheDifference("abc", "abce") << endl;
  return 0;
}

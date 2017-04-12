#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
      int left = s.find_first_not_of(' ', 0);
      int right = 0;
      int res = 0;
      while(left!=string::npos){
        right = s.find_first_of(' ', left);
        int next = s.find_first_not_of(' ', right);
        if(next==string::npos){
          if(right<0){
            res = s.size()-left;
            break;
          }
          else{
            res = right-left;
            break;
          }
        }
        else{
          left = next;
        }
      }
      return res;
    }
};

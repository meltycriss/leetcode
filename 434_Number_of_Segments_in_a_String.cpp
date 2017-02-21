#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int countSegments(string s) {
      int res = 0;
      int idx = 0;
      while(idx < s.size()){
        int status;
        status = readOneSegment(s, idx);
        if(status == 1){
          ++res;
        }
      }
      return res;
    }
    int readOneSegment(const string &s, int &index){
      int res = 0;
      while(index<s.size() && s[index]==' '){
        ++index;
      }
      while(index<s.size() && s[index]!=' '){
        res = 1;
        ++index;
      }
      return res;
    }
};

int main(){
  //caution:
  //result of "   " should be 0
  //result of "abc" should be 1
  string s = "   Hello,    my, name is John";
  s = "   ";
  s = "hello";
  cout << Solution().countSegments(s) << endl;
  return 0;
}

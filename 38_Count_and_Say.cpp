#include <string>
#include <iostream>
using namespace std;
class Solution {
  public:
    string countAndSay(int n) {
      string prev = to_string(1);
      string res = prev;
      for(int i=0; i<n-1; ++i){
        res.clear();
        int left = 0;
        for(int right=0; right<prev.size(); ++right){
          char prevC = prev[left];
          char currC = prev[right];
          if(currC!=prevC){
            int num = right-left;
            res.push_back('0'+num);
            res.push_back(prevC);
            left = right;
          }
        }
        int num = prev.size()-left;
        res.push_back('0'+num);
        res.push_back(prev[left]);
        prev = res;
      }
      return res;
    }
};

int main(){
  cout << Solution().countAndSay(6) << endl;
  return 0;
}

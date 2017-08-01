#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> res;
      for(int i=0; i<=num; ++i){
        if(i==0){
          res.push_back(0);
        }
        else{
          res.push_back(res[i&(i-1)]+1);
        }
      }
      return res;
    }

    vector<int> countBits(int num) {
      vector<int> res;
      for(int i=0; i<=num; ++i){
        int bits = countBitsAux(i);
        res.push_back(bits);
      }
      return res;
    }

    int countBitsAux(int num){
      int res = 0;
      while(num){
        ++res;
        int inverse = ~num;
        int inversePlusOne = inverse + 1;
        int lastOne = num & inversePlusOne;
        num = num & (~lastOne);
      }
      return res;
    }
};

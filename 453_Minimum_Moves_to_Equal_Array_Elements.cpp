#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
      int res = 0;
      unsigned int intMax = -1;
      intMax = (intMax << 1) >> 1;
      int min = intMax;
      for(int i=0; i<nums.size(); ++i){
        if(nums[i] < min){
          min = nums[i];
        }
        res += nums[i];
      }
      res -= min*nums.size();
      return res;
    }
};

int main(){
  unsigned int min = -1;
  min = (min << 1) >> 1;
  int t = min;
  cout << t << endl;
  return 0;
}

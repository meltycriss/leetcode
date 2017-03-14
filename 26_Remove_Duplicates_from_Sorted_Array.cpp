#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()<=1) return nums.size();
      int prev_val=nums[0];   //previous value
      int curr_pos=1;   //current position waiting to fill
      for(int i=1; i<nums.size(); ++i){
        int curr_val = nums[i];
        if(curr_val > prev_val){
          prev_val = curr_val;
          nums[curr_pos] = curr_val;
          ++curr_pos;
        }
      }
      return curr_pos;
    }
};

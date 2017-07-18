#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k = k%nums.size();
      reverse(nums, 0, nums.size()-k-1);
      reverse(nums, nums.size()-k, nums.size()-1);
      reverse(nums, 0, nums.size()-1);
    }

    //[l, r]
    void reverse(vector<int>& nums, int l, int r){
      while(l<r){
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        ++l;
        --r;
      }
    }
};

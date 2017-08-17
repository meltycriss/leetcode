#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int> res;
      for(int i=0; i<nums.size(); ++i){
        while(nums[i]-1 != i && nums[nums[i]-1] != nums[i]){
          swap(nums, nums[i]-1, i);
        }
      }
      for(int i=0; i<nums.size(); ++i){
        if(nums[i]-1 != i){
          res.push_back(nums[i]);
        }
      }
      return res;
    }

    void swap(vector<int> &nums, int i, int j){
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
};

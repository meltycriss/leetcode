class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int res = 0;
      int curr = nums.size()-1;
      for(int i=0; i<=curr; ++i){
        if(nums[i]==val){
          nums[i] = nums[curr];
          --curr;
          --i;
          ++res;
        }
      }
      res = nums.size()-res;
      return res;
    }
};

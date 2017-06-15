#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> minAfter(nums.size(), INT_MAX);
      vector<int> maxBefore(nums.size(), INT_MIN);
      int currMin = INT_MAX;
      for(int i=nums.size()-1; i>=0; --i){
        if(nums[i]<currMin){
          currMin = nums[i];
        }
        minAfter[i] = currMin;
      }
      int currMax = INT_MIN;
      for(int i=0; i<nums.size(); ++i){
        if(nums[i]>currMax){
          currMax = nums[i];
        }
        maxBefore[i] = currMax;
      }
      int left = -1;
      for(int i=0; i<minAfter.size(); ++i){
        if(nums[i] > minAfter[i]){
          left = i;
          break;
        }
      }
      int right = -1;
      for(int i=maxBefore.size()-1; i>=0; --i){
        if(nums[i] < maxBefore[i]){
          right = i;
          break;
        }
      }
      int res;
      if(left == -1){
        res = 0;
      }
      else{
        res = right-left+1;
      }
      return res;
    }
};


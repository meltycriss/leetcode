#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> mp;
      vector<int> res;
      for(int i=0; i<nums.size(); ++i){
        int numWanted = target - nums[i];
        if(mp.find(numWanted)!=mp.end()){
          res.push_back(mp[numWanted]);
          res.push_back(i);
          return res;
        }
        mp[nums[i]] = i;
      }
    }
};

#include <cmath>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
      int rob = 0;
      int noRob = 0;
      for(int i=0; i<nums.size(); ++i){
        int lastRob = rob;
        int lastNoRob = noRob;
        rob = lastNoRob + nums[i];
        noRob = max(lastRob, lastNoRob);
      }
      return max(rob, noRob);
    }
};

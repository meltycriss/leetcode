#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      vector<int> maxAfter(prices.size(),-1);
      for(int i=prices.size()-1; i>=0; --i){
        if(i==prices.size()-1) maxAfter[i] = prices[i];
        else maxAfter[i] = max(maxAfter[i+1], prices[i]);
      }
      int res = 0;
      for(int i=0; i<prices.size(); ++i){
        res = max(res, maxAfter[i]-prices[i]);
      }
      return res;
    }
};

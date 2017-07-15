#include <string>
using namespace std;

class Solution {
public:
    // Step 1. wanted form
    // x = 26k + r      :r in [1, 26] 
    // Step 2. solvable form, in which we can get r
    // x' = 26k + r'    :r' = r-1 in [0, 25], by %26, we can get r' and because mapping from r' to r is 1-1, so we can get corresponding r, that's why (n-1)%26
    // Step 3. special case when x<=26
    // still satisfy common case
    string convertToTitle(int n) {
      string res;
      while(n>0){
        res.insert(0,1,'A'+(n-1)%26);
        n = (n-1)/26;
      }
      return res;
    }

    // Step 1. wanted form
    // x = ... + x_1 * 26 + x_0      :x_k in [1, 26]
    // Step 2. solvable form 
    // x = ... + x_1' * 26 + x_0'    :x_k' in [0, 25]
    // classification discussion x_0' we get
    // 1. x_0' in [1, 25]
    // 2. x_0' = 0
    string convertToTitle(int n) {
      string res;
      while(n!=0){
        int q = n%26;
        if(q!=0){
          res.insert(0,1,'A'+q-1);
        }
        else{
          res.insert(0,1,'Z');
          n-=26;
        }
        n/=26;
      }
      return res;
    }
};

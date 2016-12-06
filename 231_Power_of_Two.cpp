class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n<=0) return false;
      int lowestOne = n & (-n);
      int reverseLowestOne = ~lowestOne;
      int excludeLowestOne = reverseLowestOne & n;
      if(excludeLowestOne) return false;
      else return true;
    }
};

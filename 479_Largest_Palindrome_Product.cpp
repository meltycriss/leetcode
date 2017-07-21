#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
      //following algo assumes largestPalindrome 2n digit width
      if(n==1){
        return 9 % 1337;
      }
      //range of valid factor
      long long min=pow(10,n-1), max=pow(10,n)-1;
      //largest palindrome possible
      long long firstHalf=max*max/pow(10,n);
      long long palindrome=buildPalindrome(firstHalf);
      while(firstHalf>=0){
        //defactor the palindrome
        for(int i=max; i>=min; --i){
          if(min*i>palindrome || max*i<palindrome){
            break;
          }
          if(palindrome%i==0){
            return palindrome % 1337;
          }
        }
        --firstHalf;
        palindrome=buildPalindrome(firstHalf);
      }
      return -1;
    }

    long long buildPalindrome(long long firstHalf){
      string rhs=to_string(firstHalf);
      string lhs=rhs;
      reverse(rhs.begin(), rhs.end());
      return stoll(lhs+rhs);
    }

    
};

#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
      if(n<=1){
        return 0;
      }
      int res = 0;
      vector<bool> v = vector<bool>(n, true);
      // can begin with i=3 and i+=2, because even numbers are not prime
      for(int i=2; i<v.size(); ++i){
        if(v[i]){
          ++res;
          // can begin with j=i*i, because non-prime numbers less than i*i have been traversed by less prime
          // can use j+=i to just use add rather than multiply
          // better add a conditional continue if(i>sqrt(n)) continue, to avoid overflow in j=i*i
          for(int j=2; i*j<v.size(); ++j){
            v[i*j]=false;
          }
        }
      }
      return res;
    }
};

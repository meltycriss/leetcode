#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
      // width w number
      int w = 0;
      while(n > 9 * pow(10,w) * (w+1)){
        n -= 9 * pow(10, w) * (w+1);
        ++w;
      }
      ++w;
      //while(n>0){
      //  n -= 9 * pow(10, w) * (w+1);
      //  ++w;
      //}
      //n += 9 * pow(10, w-1) * w;
      int p = n/w;
      int q = n%w;
      // ath number of width w number
      int a = (q>0)? p+1:p;
      // bth digit of ath number of width w number
      int b = (q>0)? q:w;
      int res = pow(10, w-1) - 1 + a;
      res %= int(pow(10, w-b+1));
      res /= pow(10, w-b);
      return res;
    }
};

int main(){
  int res = Solution().findNthDigit(pow(10,9));
  cout << res << endl;

  return 0;
}

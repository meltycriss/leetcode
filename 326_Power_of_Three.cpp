#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
      int maxExp = int(log((1<<31)-1)/log(3));
      return (n>0 && (int(pow(3,maxExp))%n==0));
    }
};

int main(){
  cout << Solution().isPowerOfThree(27) << endl;
  return 0;
}

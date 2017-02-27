#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
      long long temp_n = n;
      return int ((-1+sqrt(1+8*temp_n)) / 2);
    }
};

int main(){
  cout << Solution().arrangeCoins(8) << endl;
  return 0;
}


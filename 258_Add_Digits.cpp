#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
      if(num == 0) return 0;
      else return 1 + (num-1) % 9;
    }
};

int main(){
  cout << Solution().addDigits(38) << endl;
  return 0;
}

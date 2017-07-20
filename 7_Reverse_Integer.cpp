#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
      if(x>=0){
        int res = 0;
        while(x!=0){
          if(res>INT_MAX/10){
            return 0;
          }
          res *= 10;
          if(x%10>INT_MAX-res){
            return 0;
          }
          res += x%10;
          x /= 10;
        }
        return res;
      }
      else{
        int res = 0;
        x = -x;
        while(x!=0){
          if(res>unsigned(INT_MIN)/10){
            return 0;
          }
          res *= 10;
          if(x%10>unsigned(INT_MIN)-res){
            return 0;
          }
          res += x%10;
          x /= 10;
        }
        return -res;
      }
    }
};

int main(){
  cout << INT_MAX << endl;
  cout << unsigned(INT_MIN) << endl;
  cout << (1<<31) << endl;
  cout << signed(unsigned(1<<31)-1) << endl;
  return 0;
}

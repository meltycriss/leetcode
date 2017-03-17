// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
      long long l = 1, r = n;
      int status;
      while((r-l>1) && (status = guess((l+r)/2)) !=0){
        if(status == -1){
          r = (l+r)/2 - 1;
        }
        else{
          l = (l+r)/2 + 1;
        }
      }
      if(guess((l+r)/2) == 0) return (l+r)/2;
      else if(guess(l) == 0) return l;
      else return r;
    }
};


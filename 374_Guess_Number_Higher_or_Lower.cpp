// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
  public:
    int guessNumber(int n) {
      long long l = 1, r = n;
      int mid;
      while(l<r){
        mid = (l+r)/2;
        if(guess(mid)==1){
          l = mid + 1;
        }
        else{
          r = mid;
        }
      }
      return l;
    }
};

// i.   given l<r and floor truncation, mid is in [l,r-1]
//      caution: this is not guaranteed if l=r, that's why condition in while loop should be l<r
// ii.  the result [l,mid], [mid+1,r] ensures the size of problem shrinks
//      caution: mid in range [l,r-1] ensures the result [l,mid] and [mid+1,r] is a legal interval
// iii. combining i. and ii., there must be a moment when [l,r], l=r


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


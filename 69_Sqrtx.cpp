class Solution {
public:
    int mySqrt(int x) {
      long long l = 0;
      long long r = x;
      while(l<r){
        long long mid = (l+r)/2;
        if(mid*mid<x){
          l = mid+1;
        }
        else{
          r = mid;
        }
      }
      return l*l<=x ? l:l-1;
    }

    int mySqrt(int x) {
      int l = 0;
      int r = x;
      while(l<r){
        // better use l + (r-l)/2 to prevent overflow(l+r)
        int mid = l+(r-l)/2+1;
        // can use mid<=x/mid to prevent overflow
        // mid*mid<x = mid<x/mid, but not = mid<floor(x/mid) e.g. 3, 10
        // mid*mid<=x = mid<=x/mid = mid<=floor(x/mid)
        // caution: if use mid<=x/mid, you have to let l=mid, therefore you have to change the range of mid
        if(mid<=x/mid){
          l = mid;
        }
        else{
          r = mid-1;
        }
      }
      return l*l<=x ? l:l-1;
    }
};

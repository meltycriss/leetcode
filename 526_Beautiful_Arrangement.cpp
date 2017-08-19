#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
      vector<vector<bool> > v(N+1, vector<bool>(N+1, false));
      for(int i=1; i<v.size(); ++i){
        for(int j=1; j<v.size(); ++j){
          if(i%j==0 || j%i==0){
            v[i][j] = true;
          }
        }
      }
      vector<bool> matched(N+1, false);
      int res = countMatching(v, matched, 1);
      return res;
    }

    // given:
    //    valid matching indicator: v
    //    current matching situation: matched
    //    current awaiting matching number: i
    // return:
    //    possible matching proposals assigning number >= i
    int countMatching(const vector<vector<bool> > &v, vector<bool> &matched, int i){
      int count = 0;
      for(int j=1; j<v.size(); ++j){
        if(v[i][j] && !matched[j]){
          matched[j] = true;
          if(i==v.size()-1){
            ++count;
          }
          else{
            count += countMatching(v, matched, i+1);
          }
          matched[j] = false;
        }
      }
      return count;
    }
    // optimize:
    //    online solving valid matching indicator: v
    // other method:
    //    here the idea is number-based, i.e. assign number to pos (we recur based on i)
    //    another idea is pos-based, i.e. recur based on pos
    //    given:
    //        curr awaiting matching position: pos
    //        curr vector: v
    //    return:
    //        possible matching proposals only changing position <= pos
    //    int count(int pos, vector<int> v)
};

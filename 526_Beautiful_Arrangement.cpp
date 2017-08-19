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
    //    1. online solving valid matching indicator: v
    //    2. directly use assignment vector(vector<int>) to indicate which pos is used(vector<bool>) by swapping
    //        assignment vector<int> assign, assign[i]=k means number i is assigned to pos k
    //        1: 1, 2, 3, 4 //if 1 is assign to pos 4
    //        2: 4, 2, 3, 1 //if 2 is assign to pos 3
    //        3: 4, 3, 2, 1
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

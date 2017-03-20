#include <iostream>
#include <vector>
#include <string>
using namespace std;

// using left and right to indicate substring is more straightforward
// instead of checking whether every element in state is zero, use count to record valid substraction
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> res;
      if(s.size() < p.size()){
        return res;
      }
      vector<int> state('z'-'a'+1, 0);
      for(int i=0; i<p.size(); ++i){
        char cP = p[i];
        ++state[cP-'a'];
      }
      int left = 0, count = p.size();
      for(int right=0; right<s.size(); ++right){
        char cR = s[right];
        if(state[cR-'a']>=1){
          --count;
        }
        --state[cR-'a'];

        if(count==0){
          res.push_back(left);
        }

        if(right-left+1 == p.size()){
          char cL = s[left];
          ++state[cL-'a'];
          if(state[cL-'a']>=1){
            ++count;
          }
          ++left;
        }
      }
      return res;
    }
};

//class Solution {
//  public:
//    vector<int> findAnagrams(string s, string p) {
//      vector<int> res;
//      if(s.size() < p.size()){
//        return res;
//      }
//      vector<int> state('z'-'a'+1, 0);
//      for(int i=0; i<p.size(); ++i){
//        char cP = p[i];
//        char cS = s[i];
//        ++state[cP-'a'];
//        --state[cS-'a'];
//      }
//      for(int i=0; i<s.size()-p.size()+1; ++i){
//        if(i!=0){
//          char prevS = s[i-1];
//          ++state[prevS-'a'];
//          char currS = s[i+p.size()-1];
//          --state[currS-'a'];
//        }
//
//        bool isAnagram = true;
//        for(int j=0; j<state.size(); ++j){
//          if(state[j]!=0){
//            isAnagram = false;
//            break;
//          }
//        }
//        if(isAnagram){
//          res.push_back(i);
//        }
//      }
//      return res;
//    }
//};

int main(){
  string s = "abab";
  string p = "ab";
  vector<int> res = Solution().findAnagrams(s, p);
  for(int i=0; i<res.size(); ++i){
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}

#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    int countSubstrings(string s) {
      int res = 0;
      vector<vector<bool> > isPalind;
      isPalind.resize(s.size(), vector<bool>(s.size(), false));
      for(int k=0; k<s.size(); ++k){
        for(int i=0; i+k<s.size(); ++i){
          bool shouldUpdate = false;
          if(k==0){
            shouldUpdate = true;
          }
          else if(k==1){
            if(s[i]==s[i+k]){
              shouldUpdate = true;
            }
          }
          else{
            if(s[i]==s[i+k] && isPalind[i+1][i+k-1]){
              shouldUpdate = true;
            }
          }
          if(shouldUpdate){
            isPalind[i][i+k] = true;
            ++res;
          }
        }
      }
      return res;
    }
};

int main(){
  return 0;
}

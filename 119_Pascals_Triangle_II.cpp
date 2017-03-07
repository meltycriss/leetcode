#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> res;
      if(rowIndex < 0){
        return res;
      }
      res.resize(rowIndex+1, 0);
      for(int i=0; i<rowIndex+1; ++i){
        for(int j=i; j>=0; --j){
          if(j==0 || j==i){
            res[j] = 1;
          }
          else{
            res[j] = res[j] + res[j-1];
          }
        }
      }
      return res;
    }
};

int main(){
  vector<int> res = Solution().getRow(0);
  for(int i=0; i<res.size(); ++i){
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}

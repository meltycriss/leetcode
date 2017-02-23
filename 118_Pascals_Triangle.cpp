#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
      vector<vector<int> > res;
      if(numRows <= 0) return res;
      vector<int> currRow;
      currRow.clear();
      currRow.push_back(1);
      res.push_back(currRow);
      for(int i=1; i<numRows; ++i){
        currRow.clear();
        currRow.push_back(1);
        for(int j=1; j<i; ++j){
          int x = res[i-1][j-1] + res[i-1][j];
          currRow.push_back(x);
        }
        currRow.push_back(1);
        res.push_back(currRow);
      }
      return res;
    }
};

int main(){
  vector<vector<int> > res = Solution().generate(5);
  for(int i=0; i<res.size(); ++i){
    for(int j=0; j<res[i].size(); ++j){
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;

}

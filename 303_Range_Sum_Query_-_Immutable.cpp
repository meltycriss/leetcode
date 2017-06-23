#include <vector>
#include <iostream>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
      v.clear();
      v.resize(nums.size());
      for(int i=0; i<nums.size(); ++i){
        v[i].push_back(nums[i]);
      }
      max_width = nums.size()/10;
      for(int w=1; w<max_width; ++w){
        for(int i=0; i<nums.size(); ++i){
          int x;
          if(i+1<nums.size() && i+w<nums.size()){
            x = v[i][0] + v[i+1][w-1];
            v[i].push_back(x);
          }
        }
      }
    }

    int max_width;

    vector<vector<int> > v;

    int sumRange(int i, int j) {
      if(j-i<v[i].size()){
        return v[i][j-i];
      }
      else{
        int res = 0;
        int idx = i;
        while(idx <= j){
          if(idx + v[idx].size() - 1 <= j){
            res += v[idx][v[idx].size()-1];
            idx += v[idx].size();
          }
          else{
            res += v[idx][j-idx];
            idx = j+1;
          }
        }
        return res;
      }

      //if(i>j){
      //  return 0;
      //}
      //else if(j-i<v[i].size()){
      //  return v[i][j-i];
      //}
      //else{
      //  return sumRange(i, (i+j)/2) + sumRange((i+j)/2+1, j);
      //}
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(){
  vector<int> v;
  v.push_back(-2);
  v.push_back(0);
  v.push_back(3);
  v.push_back(-5);
  v.push_back(2);
  v.push_back(-1);

  NumArray na(v);
  cout << na.sumRange(0,2) << endl;
  return 0;


}

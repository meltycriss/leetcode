class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> res(digits.size()+1);
      for(int i=0; i<digits.size(); ++i){
        res[i+1] = digits[i];
      }
      res[0] = 0;
      bool carry = false;
      res[res.size()-1] += 1;
      if(res[res.size()-1]>9){
        carry = true;
        res[res.size()-1] -= 10;
      }
      for(int i=res.size()-2; carry && i>=0; --i){
        carry = false;
        res[i] += 1;
        if(res[i]>9){
          carry = true;
          res[i] -= 10;
        }
      }
      if(res[0]!=0){
        return res;
      }
      else{
        return vector<int>(++res.begin(), res.end());
      }
    }
};

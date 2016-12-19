#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
      vector<vector<int> > res;
      if(root==NULL) return res;
      vector<vector<int> > l = levelOrderBottom(root->left);
      vector<vector<int> > r = levelOrderBottom(root->right);
      vector<vector<vector<int> > > v;
      v.push_back(l);
      v.push_back(r);
      int minIdx = l.size()<r.size()?0:1;
      int minSize = v[minIdx].size();
      res.resize(v[1-minIdx].size()+1);
      res[res.size()-1] = vector<int>(1, root->val);
      for(int i=0; i<minSize; ++i){
        vector<int> tempL = v[0][v[0].size()-1-i];
        vector<int> tempR = v[1][v[1].size()-1-i];
        vector<int> &tempRes = res[res.size()-1-1-i];
        tempRes.insert(tempRes.begin(),tempL.begin(),tempL.end());
        tempRes.insert(tempRes.end(),tempR.begin(),tempR.end());
      }
      for(int i=0; i<res.size()-minSize-1; ++i){
        res[res.size()-1-1-minSize-i] = v[1-minIdx][v[1-minIdx].size()-minSize-i-1];
      }
      return res;
    }
};

int main(){
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n9 = new TreeNode(9);
  TreeNode *n20 = new TreeNode(20);
  TreeNode *n15 = new TreeNode(15);
  TreeNode *n7 = new TreeNode(7);
  n20->left = n15;
  n20->right = n7;
  n3->left = n9;
  n3->right = n20;
  vector<vector<int> > res = Solution().levelOrderBottom(n3);
  for(int i=0; i<res.size(); ++i){
    cout << "i: " << i << endl;
    for(int j=0; j<res[i].size(); ++j){
      if(j==0) cout << res[i][j];
      else cout << " " << res[i][j];
    }
    cout << endl;
  }
  return 0;
}

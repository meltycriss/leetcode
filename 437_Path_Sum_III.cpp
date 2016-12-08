#include <map>
using namespace std;

////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
      int count = 0;
      pathSumAux(root, sum, count);
      return count;
        
    }
    map<int, int> pathSumAux(TreeNode *root, int sum, int &count){
      if(root==NULL){
        map<int, int> res;
        return res;
      }
      //if(root->left==NULL && root->right==NULL){
      //  map<int, int> res;
      //  res[root->val] = 1;
      //  if((root->val) == sum) ++count;
      //  return res;
      //}
      map<int, int> l = pathSumAux(root->left, sum, count);
      map<int, int> r = pathSumAux(root->right, sum, count);
      map<int, int> res;
      // from left tree
      map<int, int>::iterator it = l.begin();
      while(it!=l.end()){
        int lSum = it->first;
        int currSum = lSum + (root->val);
        res[currSum] = it->second;
        ++it;
      }
      // from right tree
      it = r.begin();
      while(it!=r.end()){
        int rSum = it->first;
        int currSum = rSum + (root->val);
        if(res.find(currSum)!=r.end()){
          res[currSum] += it->second;
        }
        else{
          res[currSum] = it->second;
        }
        ++it;
      }
      // from curr root
      if(res.find(root->val)!=res.end()) ++res[root->val];
      else res[root->val] = 1;

      if(res.find(sum)!=res.end()) count+=res[sum];
      return res;
    }
};

#include <cmath>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool isBalanced(TreeNode* root) {
      return (isBalancedAux(root) >= 0);

    }
    //-1: not balanced
    //depth: balanced
    int isBalancedAux(TreeNode* root){
      if(root==NULL){
        return 0;
      }
      int l = isBalancedAux(root->left);
      int r = isBalancedAux(root->right);
      if(l==-1 || r==-1 || abs(l-r)>1){
        return -1;
      }
      return 1+max(l,r);
    }
};

using namespace std;
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
    int findBottomLeftValue(TreeNode* root) {
      return auxBottomLeftValue(root).second;
    }

    // return <depth, bottom left value>
    pair<int, int> auxBottomLeftValue(TreeNode *root){
      if(root==NULL){
        return make_pair(-1, 0);
      }
      if(root->left==NULL && root->right==NULL){
        return make_pair(0, root->val);
      }
      pair<int, int> p1 = auxBottomLeftValue(root->left);
      pair<int, int> p2 = auxBottomLeftValue(root->right);
      pair<int, int> res;
      if(p1.first >= p2.first){
        res.first = p1.first + 1;
        res.second = p1.second;
      }
      else{
        res.first = p2.first + 1;
        res.second = p2.second;
      }
      return res;
    }
};

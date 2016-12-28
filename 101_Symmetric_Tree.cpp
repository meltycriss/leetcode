/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <deque>
using namespace std;
class Solution {
  public:
    bool isSymmetric(TreeNode* root) {
      if(root==NULL) return true;
      return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
      if(left==NULL && right==NULL) return true;
      if(left==NULL || right==NULL) return false;
      return left->val==right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root){
      if(root==NULL) return true;
      queue<pair<int, TreeNode*> > q;
      deque<int> deq;
      int currLevel = 0;
      q.push(make_pair(0, root));
      while(!q.empty()){
        pair<int, TreeNode*> p = q.front();
        q.pop();
        int level = p.first;
        TreeNode* tn = p.second;
        if(level!=currLevel){
          while(!deq.empty()){
            int l = deq.back();
            int r = deq.front();
            deq.pop_back;
            deq.pop_front;
            if(l!=r) return false;
          }
          deq.clear();
          currLevel = level;
        }


      }
      while(!deq.empty()){
        int l = deq.back();
        int r = deq.front();
        deq.pop_back;
        deq.pop_front;
        if(l!=r) return false;
      }

    }

};

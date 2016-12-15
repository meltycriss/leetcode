#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // same node
      if(p==q) return p;
      // either of node is root
      if(p->val == root->val || q->val == root->val) return root;
      // one is in the left tree while the other is in the right tree
      if((p->val < root->val && q->val > root->val) || (p->val < root->val && q->val > root->val)) return root;
      // both nodes are in the left tree
      if(p->val < root->val) return lowestCommonAncestor(root->left, p, q);
      else return lowestCommonAncestor(root->right, p, q);
    }
};

void midTrav(TreeNode* root){
  if(root==NULL) return;
  midTrav(root->left);
  cout << root->val << endl;
  midTrav(root->right);
  return;
}

int main(){
  TreeNode* n0 = new TreeNode(0);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n6 = new TreeNode(6);
  TreeNode* n7 = new TreeNode(7);
  TreeNode* n8 = new TreeNode(8);
  TreeNode* n9 = new TreeNode(9);
  n2->left = n0;
  n2->right = n3;
//  n4->left = n3;
//  n4->right = n5;
//  n2->left = n0;
//  n2->right = n4;
//  n8->left = n7;
//  n8->right = n9;
//  n6->left = n2;
//  n6->right = n8;
//  midTrav(n6);
  cout << Solution().lowestCommonAncestor(n2, n3, n0)->val << endl;
//  cout << Solution().lowestCommonAncestor(n6, n2, n4)->val << endl;
  return 0;

}

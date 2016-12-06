#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root) return 0;
      int result;
      queue<pair<TreeNode*, int> > q;
      q.push(make_pair(root, 1));
      while(!q.empty()){
        TreeNode* currNode = q.front().first;
        int currDepth = q.front().second;
        result = currDepth;
        q.pop();
        if(currNode->left) q.push(make_pair(currNode->left, currDepth+1));
        if(currNode->right) q.push(make_pair(currNode->right, currDepth+1));
      }
      return result;
    }
};

int main(){
  TreeNode* l = new TreeNode(0);
  TreeNode* r = new TreeNode(1);
  TreeNode* root = new TreeNode(2);
  root->left = l;
  l->right = r;
  cout << Solution().maxDepth(root) << endl;
  return 0;
}

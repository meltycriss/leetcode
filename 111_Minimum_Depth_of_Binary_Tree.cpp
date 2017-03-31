#include <iostream>
#include <queue>
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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* currNode = p.first;
            int currDepth = p.second;
            if(currNode->left == NULL && currNode->right == NULL){
                //shouldn't use if(currNode==NULL) return currDepth - 1, think about [1,null,2]
                return currDepth;
            }
            else{
                if(currNode->left != NULL){
                    q.push(make_pair(currNode->left, currDepth+1));   
                }
                if(currNode->right != NULL){
                    q.push(make_pair(currNode->right, currDepth+1));
                }
            }
        }
    }
};

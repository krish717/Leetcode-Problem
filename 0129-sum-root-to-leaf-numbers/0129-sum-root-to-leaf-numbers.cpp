/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root,int currsum){
        if(root==NULL) return 0;
        currsum = (currsum*10)+root->val;
        if(!root->left && !root->right) return currsum;
        return sumNumbers(root->left,currsum)+sumNumbers(root->right,currsum);
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root,0);
        
    }
};
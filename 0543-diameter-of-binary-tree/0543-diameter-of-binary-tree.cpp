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
        int diameterOfBinaryTree(TreeNode* root,int &ans){
                if(root==NULL) return 0;
                int lh = diameterOfBinaryTree(root->left,ans);
                int rh = diameterOfBinaryTree(root->right,ans);
                ans = max(ans,lh+rh);
                return 1+max(lh,rh);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameterOfBinaryTree(root,ans);
        return ans;    
    }
};
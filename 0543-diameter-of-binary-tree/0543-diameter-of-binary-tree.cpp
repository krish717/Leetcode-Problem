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
        int height(TreeNode* root){
                if(root==NULL) return 0;
         int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh, rh); 
        }
       int maxi = 0;
    int diameter(TreeNode* root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi, lh+rh);
        diameter(root->left);
        diameter(root->right);
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        ans =  diameter(root);
        return ans;
        
    }
};
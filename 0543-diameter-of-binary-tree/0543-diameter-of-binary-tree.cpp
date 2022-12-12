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
                
               return 1+max((height(root->left)),(height(root->right)));
                
        }
        int diameterOfBinaryTree(TreeNode* root,int &maxi){
                if(root==NULL) return 0;
                int lh  = height(root->left);
                int rh  = height(root->right);
                maxi = max(maxi,lh+rh);
                diameterOfBinaryTree(root->left,maxi);
                diameterOfBinaryTree(root->right,maxi);
                return maxi;
        }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        return diameterOfBinaryTree(root,maxi);
        
    }
};
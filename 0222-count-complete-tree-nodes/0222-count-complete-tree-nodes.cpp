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
    int findHeightrightTree(TreeNode* root){
            int right=0;
            while(root){
                right++;
                root=root->right;
            }
            return right;
        }
        int findHeightleftTree(TreeNode* root){
            int left=0;
            while(root){
                left++;
                root=root->left;
            }
            return left;
        }
    int countNodes(TreeNode* root) {
        // if(!root) return 0;
        // return 1+countNodes(root->left)+countNodes(root->right);
        if(root==NULL) return 0;
        int lh = findHeightrightTree(root);
        int rh = findHeightleftTree(root);
        
        if(lh==rh) return (1<<lh)-1;
        
        return 1+countNodes(root->left) + countNodes(root->right);
        
    }
};
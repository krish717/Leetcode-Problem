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
        int fun(TreeNode* root,int& ans){
                if(!root) return 0;
                int left = fun(root->left,ans);
                int right = fun(root->right,ans);
                ans+=abs(left-right); 
                return left + right + root->val;
        }
        
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
         int ans = 0;
         fun(root,ans);
         return ans;
            
    }
};
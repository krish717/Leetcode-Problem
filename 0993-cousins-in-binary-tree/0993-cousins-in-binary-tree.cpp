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
        void fun(TreeNode* root, int x, int y,int& ans1,int &ans2,int count){
                if(root==NULL) return;
                if(root->val==x) ans1 = count;
                if(root->val==y) ans2 = count;
                if(root->left && root->right && root->left->val==x && root->right->val==y) return;
                if(root->left && root->right && root->left->val==y && root->right->val==x) return;
                fun(root->left,x,y,ans1,ans2,count+1);
                fun(root->right,x,y,ans1,ans2,count+1);
        }
    bool isCousins(TreeNode* root, int x, int y) {
            int ans1 = -1,ans2=-2;
            fun(root,x,y,ans1,ans2,0);
            return (ans1==ans2);
    }
};
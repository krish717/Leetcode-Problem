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
        
        void fun(TreeNode* root, int x, int y,int& depth1,int& depth2,int count){
                if(root==NULL) return;
                
                if(root->val==x) depth1 = count;
                 if(root->val==y)  depth2 = count;
                if(root->left && root->right && root->left->val==x && root->right->val==y) return;
                if(root->left && root->right && root->left->val==y && root->right->val==x) return;
                 fun(root->left,x,y,depth1,depth2,count+1);
                 fun(root->right,x,y,depth1,depth2,count+1);               
        }
    bool isCousins(TreeNode* root, int x, int y) {
        int depth1=-1,depth2=-2;
            
            if(root->val==x || root->val==y) return false;
         fun(root,x,y,depth1,depth2,0);
           return (depth1==depth2);
    }
};
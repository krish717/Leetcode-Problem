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
        void fun(TreeNode* root,vector<string>& ans,string path){
                if(!root) return;
                if(!root->left && !root->right){
                        path+=to_string(root->val);
                        ans.push_back(path);
                        return;
                }
                
                fun(root->left,ans,path+to_string(root->val)+"->");
                fun(root->right,ans,path+to_string(root->val)+"->");
        }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
            string path;
            if(!root) return ans;
            fun(root,ans,path);
            return ans;
    }
};
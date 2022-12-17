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
        void fun(TreeNode* root,string ans,vector<string>&v){
                if(!root) return;
                if(root->left==NULL && root->right==NULL){
                        ans+=to_string(root->val);
                        v.push_back(ans);
                        return;
                }
                        
                fun(root->left,ans+to_string(root->val)+"->",v);
                fun(root->right,ans+to_string(root->val)+"->",v);
        }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans = "";
          vector<string> v;
            if(!root) return v;
            fun(root,ans,v);
            return v;
    }
};
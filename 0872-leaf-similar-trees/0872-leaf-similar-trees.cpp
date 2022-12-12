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
        void leafSimilar(TreeNode* root,vector<int>& v){
                if(root==NULL) return;
                if(root->left==NULL && root->right==NULL){
                        v.push_back(root->val);
                }
                leafSimilar(root->left,v);
                leafSimilar(root->right,v);
        }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            if(root1==NULL && root2==NULL) return true;
            vector<int> v1;
            vector<int> v2;
            leafSimilar(root1,v1);
            leafSimilar(root2,v2);
            return v1==v2;
    }
};
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
       void helper(set<int>& s, TreeNode* root){
               if(root==NULL) return;
               s.insert(root->val);
               helper(s,root->left);
               helper(s,root->right);
       }
    int findSecondMinimumValue(TreeNode* root) {
             set<int> s;
             helper(s, root);
             if(s.size()==1) return -1;
            else return *(++s.begin());
             
            
    }
};
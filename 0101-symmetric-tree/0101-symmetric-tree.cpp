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
         bool isSymmetric(TreeNode* p,TreeNode* q){
                 if(p==NULL || q==NULL) return p==q;
                 if(p->val!=q->val) return false;
                 bool left = isSymmetric(p->left,q->right);
                 bool right = isSymmetric(p->right,q->left);
                 return left && right;
         }
    bool isSymmetric(TreeNode* root) {
           return isSymmetric(root->left, root->right);
    }
};
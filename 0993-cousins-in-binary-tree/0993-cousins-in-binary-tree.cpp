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
    bool isCousins(TreeNode* root, int x, int y) {
            
        queue<TreeNode*> q;
         q.push(root); 
          while(!q.empty()){
                  int size = q.size();
                  bool ans1=false,ans2=false;
                  for(int i=0; i<size; i++){
                  root = q.front();
                  q.pop();
                  if(root->val==x) ans1=true;
                  if(root->val==y) ans2=true;
                  if(root->left && root->right){
                  if(root->left->val==x && root->right->val==y || root->left->val==y && root->right->val==x)
                        return false;
                  }
                  if(root->left) q.push(root->left);
                  if(root->right) q.push(root->right);
                  }
                  if(ans1 && ans2) return true;
          } 
          
          return false;
    }
};
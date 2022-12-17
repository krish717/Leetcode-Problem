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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(root==NULL) return ans;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
            int flag=1;
            s1.push(root);
            while(!s1.empty() || !s2.empty()){
                    vector<int> temp;
                  if(flag==1){
                          int size = s1.size();
                          for(int i=0; i<size; i++){
                                  root = s1.top();
                                  s1.pop();
                                  temp.push_back(root->val);
                                  if(root->left) s2.push(root->left);
                                  if(root->right) s2.push(root->right);
                          }
                          if(s1.empty()) flag=0;
                  }else{
                         int size = s2.size();
                          for(int i=0; i<size; i++){
                                  root = s2.top();
                                  s2.pop();
                                  temp.push_back(root->val);
                                  if(root->right) s1.push(root->right);
                                  if(root->left) s1.push(root->left);
                                  
                          }
                          if(s2.empty()) flag=1;  
                  }
                    ans.push_back(temp);
            }
            return ans;
    }
};
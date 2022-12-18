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
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
            TreeNode *curr= root;
            stack<TreeNode*> s;
            while(curr!=NULL || !s.empty()){
                    if(curr!=NULL){
                            s.push(curr);
                            curr = curr->left;
                    }else{
                            TreeNode *temp = s.top()->right;
                            if(temp==NULL){
                                    root = s.top();
                                    s.pop();
                                    ans.push_back(root->val);
                                    while(!s.empty() && root==s.top()->right){
                                           root = s.top();
                                    s.pop();
                                    ans.push_back(root->val); 
                                    }
                            }else{
                                    curr = temp;
                            }
                    }
            }
            return ans;
    }
};
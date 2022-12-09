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
        stack<TreeNode *> s;
            vector<int> v;
            TreeNode *curr = root;
            while(curr!=NULL || !s.empty()){
                    if(curr!=NULL){
                            s.push(curr);
                            curr = curr->left;
                    }else{
                            TreeNode *temp = s.top()->right;
                            if(temp==NULL){
                                    temp = s.top();
                                    s.pop();
                                    v.push_back(temp->val);
                                    while(!s.empty() && temp==s.top()->right){
                                            temp = s.top();
                                            s.pop();
                                            v.push_back(temp->val);
                                    }
                            }else{
                                    curr = temp;
                            }
                    }
            }
            return v;
    }
};
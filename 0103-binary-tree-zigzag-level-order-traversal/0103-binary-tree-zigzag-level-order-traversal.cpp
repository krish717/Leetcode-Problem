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
stack<TreeNode*> s1;
stack<TreeNode*> s2;
s1.push(root);
int flag = 1;
while(!s1.empty() || !s2.empty()){
vector<int> v;
if(flag==1){
int size = s1.size();
for(int i=0; i<size; i++){
TreeNode* temp = s1.top();
s1.pop();
v.push_back(temp->val);
if(temp->left!=NULL) s2.push(temp->left); 
if(temp->right!=NULL) s2.push(temp->right);
}
if(s1.empty()) flag=0;
}else if(flag==0){
int size = s2.size();
for(int i=0; i<size; i++){
TreeNode* temp = s2.top();
s2.pop();
v.push_back(temp->val);
if(temp->right!=NULL) s1.push(temp->right); 
if(temp->left!=NULL) s1.push(temp->left);
}
if(s2.empty()) flag=1;
}
ans.push_back(v);
}
return ans;
    }
};
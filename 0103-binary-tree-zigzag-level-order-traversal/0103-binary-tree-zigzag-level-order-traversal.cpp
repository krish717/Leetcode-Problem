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
        queue<TreeNode*> q;
        bool flag=1;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> res(size);
            for(int i=0; i<size; i++){
                root = q.front();
                q.pop();
               int index = (flag) ? i : (size-1-i);
                res[index] = root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            flag = !flag;
            ans.push_back(res);
        }
        return ans;
    }
};
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
            if(root==NULL) return v;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                    int size = q.size();
                    long val=0;
                    for(int i=0; i<size; i++){
                            root = q.front();
                            q.pop();
                            if(root) val+=root->val;
                            if(root->left) q.push(root->left);
                            if(root->right) q.push(root->right);
                    }
                    double c = size;
                    v.push_back(val/c);
            }
            return v;
    }
};
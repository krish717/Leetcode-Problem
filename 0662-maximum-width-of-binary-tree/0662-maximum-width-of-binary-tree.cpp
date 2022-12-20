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
    int widthOfBinaryTree(TreeNode* root) {
            long ans = 0;
            queue<pair<TreeNode*,int>> q;
            q.push({root,0});
            while(!q.empty()){
                    long size = q.size();
                    long start = q.front().second;
                    long end = q.back().second;
                    ans = max(ans,end-start+1);
                    for(int i=0; i<size; i++){
                            root = q.front().first;
                            long id = q.front().second;
                            q.pop();
                            if(root->left){
                                    q.push({root->left,2*id+1});
                            }
                            if(root->right){
                                    q.push({root->right,2*id+2});
                            }
                            
                    }
            }
            return ans;
        
    }
};
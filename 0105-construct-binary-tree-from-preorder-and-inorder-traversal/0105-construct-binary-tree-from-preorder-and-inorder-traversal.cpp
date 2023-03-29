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
    void createMapping(vector<int>& inorder,map<int,int>& mp){
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inorderstart,int inorderend,map<int,int>& mp){
        if(index>preorder.size() || inorderstart>inorderend){
            return NULL;
        }
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
        
        root->left = solve(preorder,inorder,index,inorderstart,position-1,mp);
        root->right = solve(preorder,inorder,index,position+1,inorderend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        map<int,int> mp;
        createMapping(inorder,mp);
        TreeNode* ans = solve(preorder,inorder,index,0,inorder.size()-1,mp);
        return ans;
    }
};
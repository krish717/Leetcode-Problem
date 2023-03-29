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
    int findposition(vector<int>& inorder,int element){
        for(int i=0; i<inorder.size(); i++){
            if(element==inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inorderstart,int inorderend){
        if(index>preorder.size() || inorderstart>inorderend){
            return NULL;
        }
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findposition(inorder,element);
        
        root->left = solve(preorder,inorder,index,inorderstart,position-1);
        root->right = solve(preorder,inorder,index,position+1,inorderend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        TreeNode* ans = solve(preorder,inorder,index,0,inorder.size()-1);
        return ans;
    }
};
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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int &index,int inorderstart,int inorderend,map<int,int>& mp){
        if(index<0 || inorderstart>inorderend){
            return NULL;
        }
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
        
        root->right = solve(postorder,inorder,index,position+1,inorderend,mp);
        root->left = solve(postorder,inorder,index,inorderstart,position-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int index=postorder.size()-1;
        map<int,int> mp;
        createMapping(inorder,mp);
        TreeNode* ans = solve(postorder,inorder,index,0,inorder.size()-1,mp);
        return ans;
    }
};
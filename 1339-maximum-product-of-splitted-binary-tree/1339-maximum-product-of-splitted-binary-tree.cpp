class Solution {
public:
    int par_val; long long ans = 0, mod = 1e9 + 7;
    int solve(TreeNode* temp,TreeNode* root){
        if(!root) return 0;
        temp->left = new TreeNode(), temp->right = new TreeNode();
        long long l = solve(temp->left,root->left);
        long long r = solve(temp->right,root->right);
        return temp->val = root->val + l + r;
    }
    void dfs(TreeNode* temp){
        if(!temp) return;
        dfs(temp->left);
        dfs(temp->right);
        long long par = par_val - temp->val;
        long long chl = temp->val;
        ans = max(ans,par*chl);
    }
    int maxProduct(TreeNode* root) {
        TreeNode* temp = new TreeNode();
        solve(temp,root);
        par_val = temp->val;
        dfs(temp);
        return ans % mod;
    }
};
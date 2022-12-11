class Solution {
public:
    int ans = -1e9;
    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left), r = solve(root->right);


        int a1 = root->val + l + r;
        int a2 = root->val + l;
        int a3 = root->val + r;
        int a4 = root->val;
        int a5 = 0;

        ans = max({a1,a2,a3,a4,ans});

        return max({a2,a3,a4,a5});
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
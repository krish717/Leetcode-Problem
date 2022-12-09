class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root,int mn,int mx){
        if(!root) return;
        mn = min(mn,root->val); mx = max(mx,root->val);
        ans = max(ans,abs(mn-mx));
        solve(root->left,mn,mx);
        solve(root->right,mn,mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val,root->val);
        return ans;
    }
};
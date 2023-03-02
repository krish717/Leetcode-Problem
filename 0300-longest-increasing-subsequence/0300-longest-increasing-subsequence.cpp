class Solution {
public:
    int helper(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int notpick = 0 + helper(ind+1,prev_ind,nums,dp);
        int pick = -1e9;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            pick = 1 + helper(ind+1,ind,nums,dp);
        }
        return dp[ind][prev_ind+1] = max(notpick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(0,-1,nums,dp);
    }
};
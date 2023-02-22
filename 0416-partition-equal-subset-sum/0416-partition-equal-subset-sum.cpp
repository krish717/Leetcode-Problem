class Solution {
public:
    bool helper(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(ind==0) return (nums[ind]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notpick = helper(ind-1,target,nums,dp);
        bool pick = false;
        if(nums[ind]<=target)
         pick = helper(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = notpick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(int i=0; i<nums.size(); i++){
            totalsum+=nums[i];
        }
        
        if(totalsum%2==1) return false;
        else{
            int k = totalsum/2;
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(k+1, -1));
            return helper(n-1,k,nums,dp);
    }
    }
};
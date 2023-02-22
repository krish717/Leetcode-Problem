class Solution {
public:
    bool subsetSumtoK(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==0){
            return nums[i]==target;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        
        bool Nottaken = subsetSumtoK(i-1,target,nums,dp);
        bool taken = false;
        
        if(nums[i]<=target){
            taken = subsetSumtoK(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target] = Nottaken || taken;
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
            return subsetSumtoK(n-1,k,nums,dp);
        }
    }
};
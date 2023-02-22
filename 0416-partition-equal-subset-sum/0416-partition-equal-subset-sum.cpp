class Solution {
public:
//    bool helper(int ind,int target,vector<int>& nums,vector<vector<bool>>& dp){
//         if(target==0) return true;
//         if(ind==0) return (nums[ind]==target);
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         bool notpick = helper(ind-1,target,nums,dp);
//         bool pick = false;
//         if(nums[ind]<=target)
//          pick = helper(ind-1,target-nums[ind],nums,dp);
//         return dp[ind][target] = notpick || pick;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
    
//         int totalSum = 0;
//         for(int i=0; i<n; i++) totalSum+=nums[i];
       
//         int k = totalSum/2;
//         vector<vector<bool>> dp(n,vector<bool>(k+1,-1));
//          if(totalSum%2==1) return false;
//         else
//         return helper(n-1,k,nums,dp);
//     }

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
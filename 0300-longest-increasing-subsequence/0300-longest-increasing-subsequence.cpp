class Solution {
public:
    // int helper(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
    //     if(ind==nums.size()) return 0;
    //     if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    //     int notpick = 0 + helper(ind+1,prev_ind,nums,dp);
    //     int pick = -1e9;
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
    //         pick = 1 + helper(ind+1,ind,nums,dp);
    //     }
    //     return dp[ind][prev_ind+1] = max(notpick,pick);
    // }
    int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         // return helper(0,-1,nums,dp);
        
//         //Tabulation
//         for(int ind=n-1; ind>=0; ind--){
//             for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
//                 int notpick = 0 + dp[ind+1][prev_ind+1];
//         int pick = -1e9;
//         if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
//             pick = 1 + dp[ind+1][ind+1];
//         }
//          dp[ind][prev_ind+1] = max(notpick,pick);
//             }
//         }
//         return dp[0][-1+1];
        
        //Space optimize
         int n = nums.size();
        vector<int> prev(n+1,0),curr(n+1,0);
        // return helper(0,-1,nums,dp);
        
        //Tabulation
        for(int ind=n-1; ind>=0; ind--){
            for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
                int notpick = 0 + prev[prev_ind+1];
                int pick = -1e9;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                pick = 1 + prev[ind+1];
                }
                curr[prev_ind+1] = max(notpick,pick);
            }
            prev=curr;
        }
        return curr[-1+1];
    }
};
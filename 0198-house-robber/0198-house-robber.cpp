class Solution {
public:
    // int helper(int ind,vector<int>& nums,vector<int>& dp){
    //     if(ind==0) return nums[0];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int pick = nums[ind] + helper(ind-2,nums,dp);
    //     int notpick = 0 + helper(ind-1,nums,dp);
    //     return dp[ind] = max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // return helper(n-1,nums,dp);
        int prev = nums[0];
        int prev2 = 0;
            for(int i=1; i<n; i++){
                int pick = nums[i];
                if(i>1)
                 pick += prev2;
                int notpick = 0 + prev;
               int curr = max(pick,notpick);
                prev2 = prev;
                prev = curr;
            }
        return prev;
    }
};
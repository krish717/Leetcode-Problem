class Solution {
public:
        int fun(int ind,vector<int>& nums,vector<int>& dp){
                if(ind==0) return nums[0];
                if(ind<0) return 0;
                if(dp[ind]!=-1) return dp[ind];
                int pick = nums[ind] + fun(ind-2,nums,dp);
                int notpick = 0 + fun(ind-1,nums,dp);
                return dp[ind] = max(pick,notpick);
        }
    int rob(vector<int>& nums) {
            
            int ind = nums.size();
            vector<int> dp(ind+1,-1);
            return fun(ind-1,nums,dp);
    }
};
class Solution {
public:
        int helper(int ind,vector<int>&dp){
                if(ind==1 || ind==2) return ind;
                if(dp[ind]!=-1) return dp[ind];
            return dp[ind] = helper(ind-1,dp) + helper(ind-2,dp); 
        }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
            return helper(n,dp);
    }
};
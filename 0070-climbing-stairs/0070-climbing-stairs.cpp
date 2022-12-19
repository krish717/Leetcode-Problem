class Solution {
public:
        int fun(int ind,vector<int>& dp){
               if(ind==1 || ind==2) return ind;
                if(dp[ind]!=-1) return dp[ind];
                return dp[ind] = fun(ind-1,dp) + fun(ind-2,dp);
        }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
            return fun(n,dp);
    }
};
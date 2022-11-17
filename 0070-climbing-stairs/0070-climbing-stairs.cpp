class Solution {
public:
        // int helper(int ind,vector<int>&dp){
        //         if(ind==1 || ind==2) return ind;
        //         if(dp[ind]!=-1) return dp[ind];
        //     return dp[ind] = helper(ind-1,dp) + helper(ind-2,dp); 
        // }
    int climbStairs(int n) {
             if(n==1 || n==2) return n;
        vector<int> dp(n+1,0);
            // return helper(n,dp);
            dp[1] = 1;
            dp[2] = 2;
           
            //Tabulation
            for(int i=3; i<=n; i++){
                    dp[i] = dp[i-1] + dp[i-2];
            }   
            return dp[n];
    }
};
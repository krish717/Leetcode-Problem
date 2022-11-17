class Solution {
public:
        // int helper(int ind,vector<int>&dp){
        //         if(ind==1 || ind==2) return ind;
        //         if(dp[ind]!=-1) return dp[ind];
        //     return dp[ind] = helper(ind-1,dp) + helper(ind-2,dp); 
        // }
    int climbStairs(int n) {
             if(n==1 || n==2) return n;
        // vector<int> dp(n+1,0);
            // return helper(n,dp);
           int prev1 = 1;
           int prev2 = 1;
           
            //Tabulation
            for(int i=2; i<=n; i++){
                   int curr = prev1+prev2;
                    prev2 = prev1;
                    prev1 = curr;
            }   
            return prev1;
    }
};
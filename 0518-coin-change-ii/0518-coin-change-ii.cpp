class Solution {
public:
        int helper(int ind,int tar,vector<int>& coins, vector<vector<int>>& dp){
              if(ind==0){
                      return (tar%coins[0]==0);
              }  
               if(dp[ind][tar]!=-1) return dp[ind][tar]; 
              int nottake = helper(ind-1,tar,coins,dp);
              int take = 0;
                if(coins[ind]<=tar){
                        take = helper(ind,tar-coins[ind],coins,dp);
                }
                return dp[ind][tar] =  nottake + take;
        }
    int change(int amount, vector<int>& coins) {
            int n = coins.size();
            vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};
class Solution {
public:
        int fun(int ind,int amount, vector<int>& coins,vector<vector<int>> &dp){
                if(ind==0){
                     return (amount%coins[0]==0);
                }
                if(dp[ind][amount]!=-1) return dp[ind][amount];
                int notpick = fun(ind-1,amount,coins,dp);
                int pick = 0;
                if(coins[ind]<=amount){
                      pick =  fun(ind,amount-coins[ind],coins,dp);  
                }
                return dp[ind][amount] = pick + notpick;
        }
    int change(int amount, vector<int>& coins) {
            int n = coins.size();
            vector<vector<int>> dp(n,vector<int>(amount+1,0));
            //Base Case
            for(int i=0; i<=amount; i++){
                    dp[0][i] =  (i%coins[0]==0);
            }
            for(int ind=1; ind<n; ind++){
                    for(int target=0; target<=amount; target++){
                        int notpick = dp[ind-1][target];
                        int pick = 0;
                        if(coins[ind]<=target)
                        pick =  dp[ind][target-coins[ind]]; 
                        dp[ind][target] = pick + notpick;   
                    }
            }
        return dp[n-1][amount];
    }
};
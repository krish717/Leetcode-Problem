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
            vector<int> prev(amount+1);
            vector<int> curr(amount+1);
            //Base Case
            for(int i=0; i<=amount; i++){
                    prev[i] =  (i%coins[0]==0);
            }
            for(int ind=1; ind<n; ind++){
                    for(int target=0; target<=amount; target++){
                        int notpick = prev[target];
                        int pick = 0;
                        if(coins[ind]<=target)
                        pick =  curr[target-coins[ind]]; 
                        curr[target] = pick + notpick;   
                    }
                    prev = curr;
            }
        return prev[amount];
    }
};
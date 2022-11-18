class Solution {
public:
//         int helper(vector<int>& cost,int ind,int n, vector<int>& dp){
                
//                 if(ind>=cost.size()) return 0;
//                 if(dp[ind]!=-1) return dp[ind];
//                 int pick =    cost[ind]+ helper(cost,ind+1,n,dp);
//                 int notpick =  cost[ind]+helper(cost,ind+2,n,dp);
//                 return dp[ind] =   min(pick, notpick);
//         }
    int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            int ind=0;
            vector<int> dp(n+1);
        
           // return min(helper(cost,ind,n,dp), helper(cost,ind+1,n,dp));
            
//             // Tabulation
            dp[0] = cost[0];
            dp[1] = cost[1];
            for(int i=2; i<n; i++){
                int pick = dp[i-1];
                int notpick = dp[i-2];
                 dp[i] = cost[i] + min(pick, notpick);
            }
            return min(dp[n-1],dp[n-2]);
    }
};
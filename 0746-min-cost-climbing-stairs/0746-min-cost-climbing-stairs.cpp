class Solution {
public:
        int helper(vector<int>& cost,int ind,int n, vector<int>& dp){
                
                if(ind>=cost.size()) return 0;
                if(dp[ind]!=-1) return dp[ind];
                int pick =     helper(cost,ind+1,n,dp);
                int notpick =  helper(cost,ind+2,n,dp);
                return dp[ind] =  cost[ind] + min(pick, notpick);
        }
    int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            int ind=0;
            vector<int> dp(n+1,-1);
        
           return min(helper(cost,ind,n,dp), helper(cost,ind+1,n,dp));
            
//             // Tabulation
//             dp[0] = cost[0];
//             dp[1] = cost[1];
//             for(int i=2; i<=n; i++){
//                 int pick = dp[n-1] + cost[i-1];
//                 int notpick = dp[n-2] + cost[i-2];
//                  dp[i] = min(pick, notpick);
//             }
//             return dp[n];
    }
};
class Solution {
public:
        int helper(vector<int>& cost,int n, vector<int>& dp){
                if(n<0) return 0;
                if(n==0 || n==1) return cost[n];
                if(dp[n]!=-1) return dp[n];
                int pick =    cost[n] + helper(cost,n-1,dp);
                int notpick = cost[n] + helper(cost,n-2,dp);
                return dp[n] =   min(pick, notpick);
        }
    int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            
            vector<int> dp(n+1,-1);
        
           return min(helper(cost,n-1,dp), helper(cost,n-2,dp));
            
//             // Tabulation
            // dp[0] = cost[0];
            // dp[1] = cost[1];
            // for(int i=2; i<n; i++){
            //     int pick = dp[i-1];
            //     int notpick = dp[i-2];
            //      dp[i] = cost[i] + min(pick, notpick);
            // }
            // return min(dp[n-1],dp[n-2]);
    }
};
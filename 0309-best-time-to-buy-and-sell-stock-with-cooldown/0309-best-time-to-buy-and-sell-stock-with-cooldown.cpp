class Solution {
public:
     int helper(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy==1){
            profit = max((-prices[ind] + helper(ind+1,0,n,prices,dp)),(0 + helper(ind+1,1,n,prices,dp)));
        }else{
            profit = max((prices[ind] + helper(ind+2,1,n,prices,dp)),(0 + helper(ind+1,0,n,prices,dp)));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return helper(0,1,n,prices,dp);
    }
};
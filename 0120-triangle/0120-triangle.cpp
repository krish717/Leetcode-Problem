class Solution {
public:
    int helper(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d = triangle[i][j] + helper(i+1,j,n,triangle,dp);
        int dg = triangle[i][j] + helper(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      
        int i=0,j=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(i,j,n,triangle,dp);
    }
};
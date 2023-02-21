class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
         if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
         int ld = matrix[i][j] + helper(i-1,j-1,matrix,dp);
         int u = matrix[i][j] + helper(i-1,j,matrix,dp);
         int rd = matrix[i][j] + helper(i-1,j+1,matrix,dp);
        return dp[i][j] = min(u,min(ld,rd));
            
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = 1e9;
        for(int i=0; i<m; i++){
            maxi = min(maxi,helper(n-1,i,matrix,dp));
        }
        return maxi;
    }
};
class Solution {
public:
    // int helper(int m,int n,vector<vector<int>>& dp){
    //     if(m==0 && n==0) return 1;
    //     if(m<0 || n<0) return 0;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int up = helper(m-1,n,dp);
    //     int left = helper(m,n-1,dp);
    //     return dp[m][n] =  up + left;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        dp[0][0] = 1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                
                 int up = dp[i-1][j];
                
                 int left = dp[i][j-1];
                 dp[i][j] =  up + left;
            }
        }
        return dp[m-1][n-1];
    }
};
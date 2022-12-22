class Solution {
public:
        int fun(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
                if(j<0 || j>=matrix[0].size()) return 1e9;
                if(i==0) return matrix[0][j];
                if(dp[i][j]!=-1) return dp[i][j];
                int up = matrix[i][j] + fun(i-1,j,matrix,dp);
                int ld = matrix[i][j] + fun(i-1,j-1,matrix,dp);
                int rd = matrix[i][j] + fun(i-1,j+1,matrix,dp);
                return dp[i][j] = min(up,min(ld,rd));
        }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
            vector<vector<int>> dp(n,vector<int>(m,-1));
            int maxi = 1e9;
            for(int j=0; j<m; j++){
                    maxi = min(maxi,fun(n-1,j,matrix,dp));
            }
            return maxi;
    }
};
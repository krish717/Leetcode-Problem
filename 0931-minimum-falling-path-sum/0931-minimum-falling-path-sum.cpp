class Solution {
public:
//     int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
//          if(j<0 || j>=matrix[0].size()) return 1e9;
//         if(i==0) return matrix[0][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//          int ld = matrix[i][j] + helper(i-1,j-1,matrix,dp);
//          int u = matrix[i][j] + helper(i-1,j,matrix,dp);
//          int rd = matrix[i][j] + helper(i-1,j+1,matrix,dp);
//         return dp[i][j] = min(u,min(ld,rd));
            
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){   
                int u = matrix[i][j] + dp[i-1][j];
                 int ld = matrix[i][j];
                if(j>0){
                    ld+=dp[i-1][j-1];
                }else{
                    ld+=1e9;
                }
                int rd = matrix[i][j];
                if(j+1<m){
                     rd +=dp[i-1][j+1];
                }else{
                    rd +=1e9;
                }
                dp[i][j] = min(u,min(ld,rd));
            }
        }
        int maxi = 1e9;
        for(int i=0; i<m; i++){
            maxi = min(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};
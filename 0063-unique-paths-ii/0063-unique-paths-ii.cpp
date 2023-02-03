class Solution {
public:
//     int fun(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
//         if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
//                 if(i==0 && j==0) return 1;
//                 if(i<0 || j<0) return 0;
                 
//                 if(dp[i][j]!=-1) return dp[i][j];
//                 int pick = fun(i-1,j,dp,obstacleGrid);
//                 int notpick = fun(i,j-1,dp,obstacleGrid);
//                 return dp[i][j] = pick + notpick;
//         }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }else if(i==0 && j==0){
                    dp[i][j] = 1;
                }else{
                    int pick = 0,notpick=0;
                    if(i>0)
                     pick = dp[i-1][j];
                    if(j>0)
                     notpick = dp[i][j-1];
                    dp[i][j] = pick + notpick;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
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
        
        vector<int> prev(n);
        // dp[0][0] = 1;
        for(int i=0; i<m; i++){
            vector<int> curr(n);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    curr[j] = 0;
                }else if(i==0 && j==0){
                    curr[j] = 1;
                }else{
                    int pick = 0,notpick=0;
                    if(i>0)
                     pick = prev[j];
                    if(j>0)
                     notpick = curr[j-1];
                    curr[j] = pick + notpick;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
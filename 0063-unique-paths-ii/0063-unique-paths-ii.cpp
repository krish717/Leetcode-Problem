class Solution {
public:
        // int fun(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        //         if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        //         if(i==0 && j==0) return 1;
        //         if(i<0 || j<0) return 0;
        //         if(dp[i][j]!=-1) return dp[i][j];
        //         int up = fun(i-1,j,obstacleGrid,dp);
        //         int left = fun(i,j-1,obstacleGrid,dp);
        //         return dp[i][j] = up+left;
        // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<int> prev(m);
            for(int i=0; i<m; i++){
                    vector<int> curr(n);
                    for(int j=0; j<n; j++){
                            if(obstacleGrid[i][j]==1) curr[j] = 0;
                            else if(i==0 && j==0) curr[j] = 1;
                            else{
                                 int up=0,left=0;
                                 if(i>0) up = prev[j];
                                 if(j>0) left =  curr[j-1];
                                 curr[j] = up+left;
                            }
                    }
                    prev = curr;
            }
        return prev[n-1];
    }
};
class Solution {
public:
        // int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        //         if(i==0 && j==0) return grid[0][0];
        //         if(i<0 || j<0) return 1e9;
        //         if(dp[i][j]!=-1) return dp[i][j];
        //         int up = grid[i][j] + fun(i-1,j,grid,dp);
        //         int left = grid[i][j] + fun(i,j-1,grid,dp);
        //         return dp[i][j] = min(up,left);
        // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
            vector<int> prev(m);
            for(int i=0; i<m; i++){
                    vector<int> curr(n);
                    for(int j=0; j<n; j++){
                         if(i==0 && j==0) curr[j] =  grid[0][0];
                            else{
                                    int up=1e9,left=1e9;
                                    if(i>0){
                                            up = grid[i][j] + prev[j];
                                    }
                                    if(j>0){
                                            left = grid[i][j] + curr[j-1];
                                    }
                                   curr[j] = min(up,left);
                            }
                    }
                    prev = curr;
            }
            return prev[n-1];
    }
};
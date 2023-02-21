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
        vector<int> prev(n);
        for(int j=0; j<m; j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            vector<int> curr(n);
            for(int j=0; j<m; j++){   
                int u = matrix[i][j] + prev[j];
                 int ld = matrix[i][j];
                if(j>0){
                    ld+=prev[j-1];
                }else{
                    ld+=1e9;
                }
                int rd = matrix[i][j];
                if(j+1<m){
                     rd +=prev[j+1];
                }else{
                    rd +=1e9;
                }
                curr[j] = min(u,min(ld,rd));
            }
            prev = curr;
        }
        int maxi = 1e9;
        for(int i=0; i<m; i++){
            maxi = min(maxi,prev[i]);
        }
        return maxi;
    }
};
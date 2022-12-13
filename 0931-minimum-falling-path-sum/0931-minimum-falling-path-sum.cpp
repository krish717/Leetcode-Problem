class Solution {
public:
        // int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        //         if(j<0 || j>=matrix.size()) return 1e9;
        //         if(i==0) return  matrix[0][j];
        //         if(dp[i][j]!=-1) return dp[i][j];
        //         int s = matrix[i][j] + helper(i-1,j,matrix,dp);
        //         int l = matrix[i][j] + helper(i-1,j-1,matrix,dp);
        //         int r = matrix[i][j] + helper(i-1,j+1,matrix,dp);
        //         return dp[i][j] = min(s,min(l,r));
        // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
            
            int n = matrix.size();
            int m = matrix[0].size();
        //     int maxi = 1e9;
        //     vector<vector<int>> dp(n,vector<int>(n,-1));
        //     for(int i=0; i<m; i++){
        //        maxi = min(maxi, helper(n-1,i,matrix,dp));    
        //     }
        // return maxi;
            
            //base case
            // vector<vector<int>> dp(n,vector<int>(n,-1));
            vector<int> dp(n);
            for(int j=0; j<m ;j++){
                    dp[j] = matrix[0][j];
            }
            
            for(int i=1; i<n; i++){
                    vector<int> curr(n);
                    for(int j=0; j<m; j++){
                          int s = matrix[i][j] + dp[j];
                            int l = matrix[i][j];
                            if(j-1>=0){
                                l +=  dp[j-1];    
                            }else{
                                l+=1e9;    
                            }
                             int r = matrix[i][j];
                          if(j+1<m){
                                r +=  dp[j+1];    
                            }else{
                                r += 1e9;   
                            }
                      curr[j] = min(s,min(l,r));  
                    }
                    dp = curr;
            }
            int maxi = 1e9;
            for(int j=0; j<m; j++){
                    maxi = min(maxi, dp[j]);
            }
            return maxi;
    }
};
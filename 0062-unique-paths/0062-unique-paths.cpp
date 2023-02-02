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
        vector<int> prev(n,1);
        prev[0] = 1;
        for(int i=1; i<m; i++){
            vector<int> curr(n,1);
            for(int j=1; j<n; j++){
                
                 int up = prev[j];
                
                 int left = curr[j-1];
                 curr[j] =  up + left;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
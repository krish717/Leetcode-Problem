class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
            //base case
            for(int j=0; j<n; j++){
                    dp[n-1][j] = triangle[n-1][j]; 
            }
            
            for(int i=n-2; i>=0; i--){
                    for(int j=i; j>=0; j--){
                            int ans1 = triangle[i][j] + dp[i+1][j];
                            int ans2 = triangle[i][j] + dp[i+1][j+1];
                            dp[i][j] = min(ans1,ans2);
                    }
            }
            return dp[0][0];
    }
};
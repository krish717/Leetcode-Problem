class Solution {
public:
    // int helper(int i,int j,string s, string t,vector<vector<int>>& dp){
    //     if(j==0) return 1;
    //     if(i==0) return 0;
    //     if(s[i-1]==t[j-1]){
    //        return  dp[i][j] = helper(i-1,j-1,s,t,dp) + helper(i-1,j,s,t,dp); 
    //     }else{
    //        return dp[i][j] = helper(i-1,j,s,t,dp);
    //     }
    // }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1,0);
        vector<double> curr(m+1,0);
         prev[0] = curr[0] = 1;
        // for(int j=1; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                 curr[j] = prev[j-1] + prev[j]; 
           }else{
                 curr[j] = prev[j];
               }
            }
            prev = curr;
        }
        return (int)prev[m];
        
    }
};
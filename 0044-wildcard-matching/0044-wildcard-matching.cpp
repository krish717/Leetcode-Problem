class Solution {
public:
    bool helper(int i,int j,string &s, string &p,vector<vector<int>>& dp){
        if(i==0 && j==0) return true;
        if(i>0 && j==0) return false;
        if(i==0 && j>0){
            for(int k=1; k<=j; k++){
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j] = helper(i-1,j-1,s,p,dp);
        if(p[j-1]=='*'){
            return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(n,m,s,p,dp);
    }
};
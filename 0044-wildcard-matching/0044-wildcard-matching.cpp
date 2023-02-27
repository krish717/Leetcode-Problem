class Solution {
public:
    bool helper(int i,int j,string &s, string &p,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0){
            for(int k=0; k<=j; k++){
                if(p[k]!='*') return false;
               }
            return true;
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = helper(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    // bool helper(int ind1,int ind2,string &s,string &p,vector<vector<int>> &dp){
    //     if(ind1<0 && ind2<0) return true;
    //     if(ind2<0) return false;
    //     if(ind1<0){
    //         for(int i=0;i<=ind2;i++){
    //             if(p[i]!='*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(s[ind1]==p[ind2] || p[ind2]=='?') return dp[ind1][ind2]=helper(ind1-1,ind2-1,s,p,dp);
    //     else if(p[ind2]=='*'){
    //         return dp[ind1][ind2]=helper(ind1-1,ind2,s,p,dp) || helper(ind1,ind2-1,s,p,dp);
    //     }
    //     return dp[ind1][ind2]=false;
    // }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return helper(n-1,m-1,s,p,dp);
    }
};
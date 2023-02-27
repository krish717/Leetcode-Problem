class Solution {
public:
    // bool helper(int i,int j,string &s, string &p,vector<vector<int>>& dp){
    //     if(i==0 && j==0) return true;
    //     if(j==0 && i>0) return false;
    //     if(i==0 && j>0){
    //         for(int k=1; k<=j; k++){
    //             if(p[k-1]!='*') return false;
    //            }
    //         return true;
    //     } 
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i-1]==p[j-1] || p[j-1]=='?'){
    //         return dp[i][j] = helper(i-1,j-1,s,p,dp);
    //     }
    //     if(p[j-1]=='*'){
    //         return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
    //     }
    //     return dp[i][j] = false;
    // }
   
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);
       for(int i = 1; i<m+1; ++i){
            bool flag = true;
            for(int ii = 1; ii<=i; ++ii){
                if(p[ii-1]!='*'){
                    flag = false;
                    break;
                }
            }
            prev[i] = flag;
        }
        prev[0] = true;
        
        for(int i=1; i<=n; i++){
            curr[0] = 0;
            for(int j=1; j<=m; j++){
                 if(s[i-1]==p[j-1] || p[j-1]=='?'){
             curr[j] = prev[j-1];
        }
       else if(p[j-1]=='*'){
             curr[j] = prev[j] || curr[j-1];
        }else
         curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};
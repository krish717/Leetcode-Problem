class Solution {
public:
        int fib(int i,vector<int> &dp){
                if(i<=1) return i;
                if(dp[i]!=-1) return dp[i];
                return dp[i] = fib(i-1,dp) + fib(i-2,dp);
                
        }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);    
    }
};
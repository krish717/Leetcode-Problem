class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int range,int n){
        if(!n) return 0;
        if(i > range) return 1e9;
        if(dp[i][n] != -1) return dp[i][n];

        int op1 = 1e9, op2 = 1e9;
        if(n-(i*i) >= 0) op1 = 1 + solve(i,range,n-(i*i));
        op2 = solve(i+1,range,n);

        return dp[i][n] = min(op1,op2);
    }
    int numSquares(int n) {
        dp.resize(ceil(sqrt(n))+1,vector<int>(n+1,-1));
        return solve(1,ceil(sqrt(n)),n);
    }
};
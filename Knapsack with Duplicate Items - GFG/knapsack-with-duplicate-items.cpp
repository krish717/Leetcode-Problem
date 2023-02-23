//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int helper(int ind,int w,int val[], int wt[],vector<vector<int>>& dp){
    //     if(ind==0){
    //       return ((w/wt[0])*val[0]);
    //     }
    //     if(dp[ind][w]!=-1) return dp[ind][w];
    //     int notpick = 0 + helper(ind-1,w,val,wt,dp);
    //     int pick = INT_MIN;
    //     if(wt[ind]<=w){
    //         pick = val[ind] + helper(ind,w-wt[ind],val,wt,dp);
    //     }
    //     return dp[ind][w] = max(notpick,pick);
    // }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        for(int i=0; i<=W; i++){
            dp[0][i] = ((i/wt[0])*val[0]);
        }
        for(int ind=1; ind<N; ind++){
            for(int weight=0; weight<=W; weight++){
                int notpick = 0 + dp[ind-1][weight];
        int pick = INT_MIN;
        if(wt[ind]<=weight){
            pick = val[ind] + dp[ind][weight-wt[ind]];
        }
         dp[ind][weight] = max(notpick,pick);
            }
        }
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
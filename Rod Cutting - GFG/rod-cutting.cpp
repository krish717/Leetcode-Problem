//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//   int helper(int ind,int n,int price[],vector<vector<int>>& dp){
//       if(ind==0) return price[0]*n;
//       if(dp[ind][n]!=-1) return dp[ind][n];
//       int notpick = 0 + helper(ind-1,n,price,dp);
//       int pick = INT_MIN;
//       int rodlength = ind+1;
//       if(rodlength<=n){
//           pick = price[ind] + helper(ind,n-rodlength,price,dp);
//       }
//       return dp[ind][n] = max(notpick,pick);
//   }
    int cutRod(int price[], int n) {
        //code here
  
        vector<vector<int>> dp(n,vector<int>(n+1));
        for(int i=0; i<=n; i++){
            dp[0][i] = price[0]*i;
        }
        for(int ind=1; ind<n; ind++){
            for(int tar=0; tar<=n; tar++){
                int notpick = 0 + dp[ind-1][tar];
      int pick = -1e9;
      int rodlength = ind+1;
      if(rodlength<=tar){
          pick = price[ind] + dp[ind][tar-rodlength];
      }
       dp[ind][tar] = max(notpick,pick);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
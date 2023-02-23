//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int helper(int ind,int n,int price[],vector<vector<int>>& dp){
      if(ind==0) return price[0]*n;
      if(dp[ind][n]!=-1) return dp[ind][n];
      int notpick = 0 + helper(ind-1,n,price,dp);
      int pick = INT_MIN;
      int rodlength = ind+1;
      if(rodlength<=n){
          pick = price[ind] + helper(ind,n-rodlength,price,dp);
      }
      return dp[ind][n] = max(notpick,pick);
  }
    int cutRod(int price[], int n) {
        //code here
  
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(n-1,n,price,dp);
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
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long int helper(int ind,int sum,int coins[], vector<vector<long long int>>& dp){
      if(ind==0) return (sum%coins[0]==0);
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      long long int notpick = helper(ind-1,sum,coins,dp);
      long long int pick = 0;
      if(coins[ind]<=sum){
          pick = helper(ind,sum-coins[ind],coins,dp);
      }
      return dp[ind][sum] = notpick + pick;
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return helper(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int helper(int ind,vector<int>& height,int k,vector<int> &dp){
      if(ind==0) return 0;
      if(dp[ind]!=-1) return dp[ind];
      int ministeps = INT_MAX;
      for(int j=1; j<=k; j++){
          if(ind-j>=0){
          int jump = helper(ind-j,height,k,dp)+abs(height[ind]-height[ind-j]);
           ministeps = min(jump,ministeps);
          }
      }
      return dp[ind] = ministeps;
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int ind=1; ind<n; ind++){
            int ministeps = INT_MAX;
             for(int j=1; j<=k; j++){
          if(ind-j>=0){
          int jump = helper(ind-j,height,k,dp)+abs(height[ind]-height[ind-j]);
           ministeps = min(jump,ministeps);
          }
      }
      dp[ind] = ministeps;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
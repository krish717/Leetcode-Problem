//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int fun(int ind, int target, vector<int>& arr,vector<vector<int>> &dp){
    if(ind==0){
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target==arr[0]) return 1;
        else return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notpick =  fun(ind-1,target,arr,dp);
    int pick = 0;
    if(arr[ind]<=target) pick = fun(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] =  notpick + pick;
}
 int parition(int d,vector<int>& nums){
     int n = nums.size();
     vector<vector<int>> dp(n,vector<int>(d+1,-1));
                
               
               
           return fun(n-1,d,nums,dp);
                
 }
int countparition(int n, int d, vector<int>& arr){
    int totalsum = 0;
    
    for(int i=0; i<n; i++) totalsum+=arr[i];
    if((totalsum-d<0) || (totalsum-d)%2) return false;
    return parition(((totalsum-d)/2),arr);
}
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        return countparition(n,target,A);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int helper(int ind,vector<int>arr, int sum,vector<vector<int>>& dp){
    if(sum==0) return true;
    if(ind==0) return (arr[0]==sum);
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int notpick = helper(ind-1,arr,sum,dp);
    int pick = false;
    if(sum>=arr[ind])
     pick = helper(ind-1,arr,sum-arr[ind],dp);
     return dp[ind][sum] = notpick || pick;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
       vector<int> prev(sum+1,0);
          vector<int> curr(sum+1,0);
        //base case
        
            prev[0] = curr[0] = 1;
        
        if(arr[0]<=sum) prev[arr[0]] = 1;
        
        for(int ind=1; ind<n; ind++){
         
            for(int target=1; target<=sum; target++){
                int notpick = prev[target];
                int pick = 0;
                if(target>=arr[ind])
                pick = prev[target-arr[ind]];
                curr[target] = notpick || pick;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
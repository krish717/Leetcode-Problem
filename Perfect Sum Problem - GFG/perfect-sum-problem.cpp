//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1000000007;
	int helper(int arr[], int n, int sum,vector<vector<int>>& dp){
	   if(n==0){
	       if(sum==0 && arr[0]==0) return 2;
	       if(sum==0 || arr[0]==sum) return 1;
	       return 0;
	   }
	    if(dp[n][sum]!=-1) return dp[n][sum];
	   
	    int nt = helper(arr,n-1,sum,dp)%mod;
	    int t = 0;
	    if(arr[n]<=sum)
	    t =  helper(arr,n-1,sum-arr[n],dp)%mod;
	    return dp[n][sum] = (nt+t)%mod;
	   
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
          vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return helper(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
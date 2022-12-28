//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //  int fun(int ind,int W, int wt[], int val[],vector<vector<int>>& dp){
         
    //      if(ind==0){
    //          if(wt[0]<=W) return val[0];
    //          else return 0;
    //      }
    //      if(dp[ind][W]!=-1) return dp[ind][W];
    //      int notpick = 0 + fun(ind-1,W,wt,val,dp);
    //      int pick = INT_MIN;
    //      if(wt[ind]<=W){
    //          pick  = val[ind] + fun(ind-1,W-wt[ind],wt,val,dp);
    //      }
    //      return dp[ind][W] =  max(notpick,pick);
    //  }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W+1,0);
       vector<int> curr(W+1,0);
       for(int i=wt[0]; i<=W; i++){
           prev[i] = val[0];
       }
       for(int ind=1; ind<n; ind++){
           for(int weight=0; weight<=W; weight++){
               int notpick = 0 + prev[weight];
                int pick = INT_MIN;
                 if(wt[ind]<=weight){
             pick  = val[ind] + prev[weight-wt[ind]];
         }
         curr[weight] = max(notpick,pick);
           }
           prev = curr;
       }
       return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
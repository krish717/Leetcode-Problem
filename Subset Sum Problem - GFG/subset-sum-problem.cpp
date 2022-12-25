//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool fun(int ind, int k, vector<int> &arr,vector<vector<int>>& dp){
    if(k==0) return true;
    if(ind==0) return k==arr[ind];
    if(dp[ind][k]!=-1) return dp[ind][k];
    bool nottake = fun(ind-1,k,arr,dp);
    bool take = false;
    if(k>=arr[ind])
     take = fun(ind-1,k-arr[ind],arr,dp);
    return dp[ind][k] = nottake || take;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int k = sum;
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return fun(n-1,k,arr,dp);
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
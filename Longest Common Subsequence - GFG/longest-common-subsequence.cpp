//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // int helper(int ind1, int ind2, string s1, string s2,vector<vector<int>>& dp){
    //     if(ind1==0 || ind2==0) return 0;
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(s1[ind1-1]==s2[ind2-1]) return 1 + helper(ind1-1,ind2-1,s1,s2,dp);
    //     return dp[ind1][ind2] = max(helper(ind1-1,ind2,s1,s2,dp),helper(ind1,ind2-1,s1,s2,dp));
    // }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n = x;
        int m = y;
        // vector<int> prev(x+1,0);
        // vector<int> curr(x+1,0);
        // for(int i=0; i<=x; i++) prev[0] = 0;
        
        // for(int ind1=1; ind1<=x; ind1++){
             
        //     for(int ind2=1; ind2<=y; ind2++){
        //         if(s1[ind1-1]==s2[ind2-1]) 
        //          curr[ind2] = 1 + prev[ind2-1];
        //         else
        //       curr[ind2] = max(prev[ind2],curr[ind2-1]);
        //     }
        //     prev = curr;
        // }
        // return curr[y];
        
         vector<int> prev(m+1,0);
            vector<int> curr(m+1,0);
             for(int i=0; i<=n; i++) prev[0] = 0;
            // for(int j=0; j<=m; j++) dp[0][j] = 0;
            for(int i=1; i<=n; i++){
                    
                    for(int j=1; j<=m; j++){
                         if(s1[i-1]==s2[j-1])  curr[j] = 1+prev[j-1];
                         else curr[j] = max(prev[j],curr[j-1]);   
                    }
                    prev = curr;
            }
            return curr[m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
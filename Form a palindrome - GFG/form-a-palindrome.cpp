//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int longestPalindromeSubseq(string s) {
         string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.size();
        int m = s2.size();
        vector<int> prev(m+1),curr(m+1);
        for(int i=0; i<=n; i++) prev[0] = 0;
        // for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int ind1=1; ind1<=n; ind1++){
             for(int ind2=1; ind2<=m; ind2++){
                  if(s[ind1-1]==s2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
                  else  curr[ind2] = max(prev[ind2],curr[ind2-1]);
             }
            prev = curr;
        }
        return prev[m];
    }
    int findMinInsertions(string S){
        // code here 
        int ans = longestPalindromeSubseq(S);
        return S.size()-ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
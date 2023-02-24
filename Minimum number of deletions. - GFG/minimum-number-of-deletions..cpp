//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

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
int minDeletions(string str, int n) { 
    //complete the function here 
    int ans = longestPalindromeSubseq(str);
    return n-ans;
} 
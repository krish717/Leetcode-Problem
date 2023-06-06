//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//   void helper(int ind,int n,string s,string str,vector<string> &ans,int &count){
// 	    if(ind>=n){
// 	        if(str.size()){
// 	            ans.push_back(str);
// 	            count++;
// 	            return;
// 	        }
// 	        return;
// 	    }
// 	    str.push_back(s[ind]);
// 	    helper(ind+1,n,s,str,ans,count);
// 	    str.pop_back();
	    
// 	    helper(ind+1,n,s,str,ans,count);
// 	}
const int MOD = 1e9 + 7;
		int AllPossibleStrings(string s){
		    // Code here
		   int n = s.size();
    vector<int> dp(n + 1, 0);
    vector<int> lastOccurrence(256, -1);

    dp[0] = 1;  // Empty string has one subsequence
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        if (lastOccurrence[s[i - 1]] != -1) {
            dp[i] = (dp[i] - dp[lastOccurrence[s[i - 1]] - 1] + MOD) % MOD;
        }
        lastOccurrence[s[i - 1]] = i;
    }

    return dp[n];
		}
    string betterString(string str1, string str2) {
        // code here
        int a = AllPossibleStrings(str1);
        int b = AllPossibleStrings(str2);
        if(a==b) return str1;
        if(a>b) return str1;
        else return str2;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // int n = x;
        // int m = y;
        vector<int> prev(y+1,0);
        vector<int> curr(y+1,0);
        for(int i=0; i<=x; i++) prev[0] = 0;
        
        for(int ind1=1; ind1<=x; ind1++){
             
            for(int ind2=1; ind2<=y; ind2++){
                if(s1[ind1-1]==s2[ind2-1]) 
                 curr[ind2] = 1 + prev[ind2-1];
                else
              curr[ind2] = max(prev[ind2],curr[ind2-1]);
            }
            prev = curr;
        }
        return curr[y];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	     int x=str1.size();
    int y=str2.size();
    int lc = lcs(x,y,str1,str2);
    return (x+y)-(2*lc);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
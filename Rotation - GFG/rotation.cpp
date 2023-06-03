//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int l=0,h=n-1,ans=INT_MAX,index=-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[l]<=arr[h]){
              if(arr[l]<ans){
                  index = l;
                    ans = arr[l];
                }
              break;
            }
            if(arr[l]<=arr[mid]){
                if(arr[l]<ans){
                    index = l;
                    ans = arr[l];
                }
                l = mid+1;
            }else{
                if(arr[mid]<ans){
                    index = mid;
                    ans = arr[mid];
                }
                h = mid-1;
            }
        }
        return index;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
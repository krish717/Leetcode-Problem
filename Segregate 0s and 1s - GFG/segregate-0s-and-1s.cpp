//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        // int count0 = 0;
        // for(int i=0; i<n; i++){
        //     if(arr[i]==0) count0++;
        // }
        // for(int i=0; i<count0; i++){
        //     arr[i] = 0;
        // }
        // for(int i=count0; i<n; i++){
        //     arr[i] = 1;
        // }
        
        int i=0; int j=n-1;
        while(i<j){
           while(i<j && arr[i]==0) i++;
           while(i<j && arr[j]==1) j--;
           if(i<j) swap(arr[i++],arr[j--]);
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void fun(vector<int> arr, int N,int ind,vector<int>&ans,int sum){
    if(ind>=N){
        ans.push_back(sum);
        return;
    }
    fun(arr,N,ind+1,ans,sum);
    sum+=arr[ind];
     fun(arr,N,ind+1,ans,sum);
     sum-=arr[ind];
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
       
        
        fun(arr,N,0,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
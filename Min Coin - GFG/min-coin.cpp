//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int helper(int ind,int amount,vector<int>nums,vector<vector<int>>& dp){
	    if(ind==0){
	        if(amount%nums[0]==0) return amount/nums[0];
	        else return 1e9;
	    }
	    if(dp[ind][amount]!=-1) return dp[ind][amount];
	    int notpick = 0 + helper(ind-1,amount,nums,dp);
	    int pick = INT_MAX;
	    if(nums[ind]<=amount){
	        pick = 1 + helper(ind,amount-nums[ind],nums,dp);
	    }
	    return dp[ind][amount] = min(notpick,pick);
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n = nums.size();
	    vector<int> prev(amount+1);
	    for(int i=0; i<=amount; i++){
	        if(i%nums[0]==0){
	            prev[i] = i/nums[0];
	        }else{
	            prev[i] = 1e9;
	        }
	    }
	    for(int ind=1; ind<n; ind++){
	        vector<int> curr(amount+1);
	        for(int a=0; a<=amount; a++){
	            int notpick = 0 + prev[a];
	            int pick = INT_MAX;
	            if(nums[ind]<=a){
	            pick = 1 + curr[a-nums[ind]];
	           }
	            curr[a] = min(notpick,pick);
	        }
	        prev= curr;
	    }
	    if(prev[amount]==1000000000){
	        return -1;
	    }else{
	        return prev[amount];
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
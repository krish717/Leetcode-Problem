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
	    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
	    long long int ans =  helper(n-1,amount,nums,dp);
	    if(ans==1000000000){
	        return -1;
	    }else{
	        return ans;
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
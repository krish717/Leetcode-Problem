class Solution {
public:
    // int helper(int ind,vector<int>& nums,vector<int>& dp){
    //     if(ind==0) return nums[0];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int first = nums[ind] + helper(ind-2,nums,dp);
    //     int second = 0 + helper(ind-1,nums,dp);
    //     return dp[ind] =  max(first, second);
    // }
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n+1,-1);
        // return helper(n-1,nums,dp);
        
        
        //Tabulation
        int n = nums.size();
        
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int first = nums[i];
            if(i>1)
            first += prev2;
            int second = 0 + prev;
            int curr =  max(first, second);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
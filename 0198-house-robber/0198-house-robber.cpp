class Solution {
public:
        // int helper(int i, vector<int>& nums, vector<int>& dp){
        //         if(i==0) return nums[i];
        //         if(i<0) return 0;
        //         if(dp[i]!=-1) return dp[i];
        //         int pick = nums[i] + helper(i-2, nums, dp);
        //         int notpick = 0 + helper(i-1, nums, dp);
        //         return dp[i] = max(pick, notpick);
        // }
    int rob(vector<int>& nums) {
            int n = nums.size();
           int prev2=0,prev=nums[0];
         
            for(int i=1; i<n; i++){
                    int pick;
                    if(i==1)
                      pick = nums[i] + 0;
                    else
                     pick = nums[i] + prev2;
                    int notpick = 0 + prev;
                    int curr = max(pick, notpick);
                    prev2 = prev;
                    prev = curr;
            }
       return prev;
    }
};
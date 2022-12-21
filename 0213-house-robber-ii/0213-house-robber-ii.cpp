class Solution {
public:
        int robs(vector<int>& nums) {
         int n = nums.size();
         int prev2 = 0;
            int prev = nums[0];
            for(int i=1; i<n; i++){
                    int pick;
                    if(i>1){
                            pick = nums[i] + prev2;
                    }else{
                            pick = nums[i];
                    }
                    int notpick = 0 + prev;
                    
                    int curr = max(pick,notpick);
                    prev2 = prev;
                    prev = curr;
            }
            return prev;
    }
    int rob(vector<int>& nums) {
            
         int n = nums.size();
            if(n==1) return nums[0];
        vector<int> temp1,temp2;
            for(int i=0; i<n; i++){
                    if(i!=0) temp1.push_back(nums[i]);
                    if(i!=n-1) temp2.push_back(nums[i]);
            }
            int ans1 = robs(temp1);
            int ans2 = robs(temp2);
            return max(ans1,ans2);
    }
};
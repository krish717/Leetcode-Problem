class Solution {
public:
        bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
          if(totalSum%2!=0) return false;
                int k = totalSum/2;
    vector<bool> prev(k+1,0);
    prev[0] = 1;
    if(nums[0]<=k)
    prev[nums[0]] = 1;
    for(int ind=1; ind<nums.size(); ind++){
         vector<bool> curr(k+1);
        curr[0] = 1;
        for(int target=1; target<=k; target++){
            bool nottake = prev[target];
            bool take = false;
            if(nums[ind]<=target){
                take = prev[target-nums[ind]];
            }
            curr[target] = nottake || take;
        }
        prev = curr;
    }
    return prev[k];
            
    }
};
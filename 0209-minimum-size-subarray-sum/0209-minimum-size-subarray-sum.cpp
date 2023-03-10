class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=INT_MAX;
        int i=0,j=0,n=nums.size(),sum=0;
        while(j<n){
            sum=sum+nums[j];
            if(sum<target) j++;
             else if(sum>=target){ 
                while(sum>=target){
                    mini = min(mini,j-i+1);
                    sum=sum-nums[i];
                     i++;
                }
                j++;
            }
        }
        return (mini==INT_MAX) ? 0 : mini;
    }
};
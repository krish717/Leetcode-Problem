class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<=1) return 0;
        int i=0,j=0;
        int pro=1,ans=0;
        while(j<n){
            pro=pro*nums[j];
            if(pro<k){
                ans = ans + j-i+1;
                j++;
            }else if(pro>=k){
                while(pro>=k){
                pro=pro/nums[i];
                i++;
                }
                ans = ans + j-i+1;
                j++;
            }
            
        }
        return ans;
    }
};
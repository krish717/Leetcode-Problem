class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]<=n && nums[i]>0 && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(i+1!=nums[i]) return i+1;
        }
        return n+1;
    }
};
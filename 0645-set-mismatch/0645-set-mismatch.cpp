class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        // vector<int> v;
        for(int i=0; i<n; i++){
            if(i+1!=nums[i]) return {nums[i],i+1};
        }
        return {-1,-1};
    }
};
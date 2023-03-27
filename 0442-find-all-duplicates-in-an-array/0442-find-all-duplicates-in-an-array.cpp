class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for(int i=0; i<n; i++){
            if(i+1!=nums[i]) v.push_back(nums[i]);
        }
        return v;
    }
};
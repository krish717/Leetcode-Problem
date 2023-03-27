class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }else{
                i++;
            }
        }
        
        //Traverse and find Duplicate
        for(int i=0; i<n; i++){
            if(i!=nums[i]) return nums[i];
        }
        return -1;
    }
};
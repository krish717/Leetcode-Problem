class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0,j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) count++;
            else{
                nums[j++] = nums[i];
            }
        }
        for(int i=0; i<count; i++){
            nums[j++] = 0;
        }
    }
};
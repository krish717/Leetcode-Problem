class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        while(i<=j){
            int mid = i+j/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) i++;
            else j--;
        }
        return -1;
    }
};
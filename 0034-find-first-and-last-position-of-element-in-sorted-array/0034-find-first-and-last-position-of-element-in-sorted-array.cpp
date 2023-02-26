class Solution {
public:
    int first(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;
        int res=-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                res = mid;
                e=mid-1;
            }
            else if(target>nums[mid]) s=mid+1;
            else e=mid-1;
        }
       return res;
    }
    int second(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;
        int res=-1;
        while(s<=e){
            int mid = s + (e-s)/2;
             if(nums[mid]==target){
                res = mid;
                s=mid+1;
            }
            else if(target<nums[mid]) e=mid-1;
            else s=mid+1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // if(nums.size()==0) return {-1,-1};
        // if(nums.size()==1 && target!=nums[0]){
        //     return {-1,-1};
        // }
        int firstpos = first(nums,target);
        int secondpos = second(nums,target);
        return {firstpos,secondpos};
    }
};
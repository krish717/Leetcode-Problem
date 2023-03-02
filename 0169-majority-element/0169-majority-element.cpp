class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int maxi=0;
        int val=0;
        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i])!=um.end()){
                if(maxi<um[nums[i]]){
                maxi = um[nums[i]];
                val = nums[i];
                }
            }
        }
        return val;
    }
};
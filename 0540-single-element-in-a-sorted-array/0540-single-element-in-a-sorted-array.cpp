class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(um[nums[i]]==1){
                ans = nums[i];
            }
        }
        return ans;
    }
};
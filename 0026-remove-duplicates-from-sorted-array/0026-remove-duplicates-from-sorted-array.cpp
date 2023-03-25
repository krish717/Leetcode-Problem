class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]] = 1;
        }
        int count=0;
        int k=0;
        for(int i=0; i<nums.size(); i++){
            if(um.count(nums[i])>0){
                count++;
                nums[k++] = nums[i];
                um.erase(nums[i]);
            }
        }
        return count;
    }
};
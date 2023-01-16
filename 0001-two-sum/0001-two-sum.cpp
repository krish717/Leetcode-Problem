class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
            unordered_map<int,int> um;
            for(int i=0; i<nums.size(); i++){
                    if(um.find(target-nums[i])!=um.end()){
                          v.push_back(um[target-nums[i]]);
                          v.push_back(i);
                            return v;
                    }else{
                            um[nums[i]] = i;
                    }
            }
            return v;
    }
};
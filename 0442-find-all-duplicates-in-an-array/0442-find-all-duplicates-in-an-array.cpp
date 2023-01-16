class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       unordered_map<int,int> um;
            for(int i=0; i<nums.size(); i++){
                    um[nums[i]]++;
            }
            vector<int> v;
            for(int i=0; i<nums.size(); i++){
                    if(um[nums[i]]>1){
                            v.push_back(nums[i]);
                            um.erase(nums[i]);
                    }
            }
            return v;
    }
};
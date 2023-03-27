class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]] = 1;
        }
        for(int i=1; i<=nums.size(); i++){
            if(um.count(i)<1){
                v.push_back(i);
            }
        }
        return v;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> um;
            for(int i=0; i<nums.size(); i++){
                    um[nums[i]]++;
            }
            vector<int> v;
            for(int i=1; i<=nums.size(); i++){
                    if(um.find(i)==um.end()){
                            v.push_back(i);
                    }
            }
            return v;
    }
};
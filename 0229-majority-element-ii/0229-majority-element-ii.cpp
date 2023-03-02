class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size(); 
        for(int i=0; i<n; i++){
            um[nums[i]]++;
        }
        vector<int> v;
        int s = n/3;
         for(int i=0; i<n; i++){
            if(um.find(nums[i])!=um.end()){
                if(um[nums[i]]>s)
                v.push_back(nums[i]);
                um.erase(nums[i]);
            }
        }
        return v;
    }
};
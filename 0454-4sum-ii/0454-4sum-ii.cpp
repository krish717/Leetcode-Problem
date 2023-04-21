class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      unordered_map<int,int> um;
        for(auto it1:nums1){
            for(auto it2:nums2){
                um[it1+it2]++;
            }
        }
        int count=0;
         for(auto it1:nums3){
            for(auto it2:nums4){
                if(um.find(0-it1-it2)!=um.end()) count+=um[0-it1-it2];
            }
        }
        return count;
    }
};
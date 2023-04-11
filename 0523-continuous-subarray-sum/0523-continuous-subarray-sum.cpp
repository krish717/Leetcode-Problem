class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       
            unordered_map<int,int> umpp;
            umpp[0] = 0;
            int sum = 0;
            for(int i=0; i<nums.size(); i++){
                    sum +=nums[i];
                    if(!umpp.count(sum%k)) umpp[sum%k] = i+1;
                    else if(umpp.count(sum%k) && umpp[sum%k]<i) return true;
            }
            return false;
    }
};
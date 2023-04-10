class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>  um;
        um[0] = 1;
        int n = nums.size();
        int count=0;
        int presum=0;
        for(int i=0; i<n; i++){
            presum+=nums[i];
            int rem = presum - k;
            count+=um[rem];
            um[presum] += 1;
        }
        return count;
    }
};
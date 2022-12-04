class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> pre; long long s = 0;
        for(int i=0;i<nums.size();i++){
            s += nums[i]; pre.push_back(s);
        }
        long long ans = 1e9, idx;
        for(int i=0;i<nums.size();i++){
            long long avg1 = pre[i]/(i+1);
            long long avg2 = i == nums.size()-1 ? 0 : (pre.back()-pre[i])/(nums.size()-i-1);
            long long diff = abs(avg1-avg2);
            if(diff < ans) ans = diff, idx = i;
        }
        return idx;
    }
};
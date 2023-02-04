class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size()<4) return ans;
        for(int i=0; i<nums.size()-3; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            long long newt = target - nums[i];
            for(int j=i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
              long long newTarget = newt-nums[j];
                int start = j+1, end = nums.size()-1;
                while(start<end){
                    int twosum = nums[start]+nums[end];
                    if(twosum<newTarget) start++;
                    else if(twosum>newTarget) end--;
                    else{
                        vector<int> quadruplets;
                        quadruplets.push_back(nums[i]);
                        quadruplets.push_back(nums[j]);
                        quadruplets.push_back(nums[start]);
                        quadruplets.push_back(nums[end]);
                        ans.push_back(quadruplets);
                        
                        while(start<end && nums[start]==nums[start+1]) start++;
                         while(start<end && nums[end]==nums[end-1]) end--;
                        start++;
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
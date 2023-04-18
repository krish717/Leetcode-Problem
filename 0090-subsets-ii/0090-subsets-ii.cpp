class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int> &v,vector<int>& nums,int n,int ind){
        if(ind>=n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        fun(ans,v,nums,n,ind+1);
        v.pop_back();
        
         while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            ind++;
        }
        
        fun(ans,v,nums,n,ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
         fun(ans,v,nums,n,0);
        return ans;
    }
};
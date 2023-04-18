class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int> &v,vector<int>& nums,int n,int ind){
        if(ind>=n){
            ans.push_back(v);
            return;
        }
        fun(ans,v,nums,n,ind+1);
        v.push_back(nums[ind]);
        fun(ans,v,nums,n,ind+1);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
         fun(ans,v,nums,n,0);
        return ans;
    }
};
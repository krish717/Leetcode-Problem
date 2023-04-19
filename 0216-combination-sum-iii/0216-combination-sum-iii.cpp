class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>& v,int n, int target,int ind,int k){
       if(ind>n) return;
        if(k<0) return;
        if(k==0){
            if(target==0){
            ans.push_back(v); 
           }
            return;
        }
        if(target==0){
            if(k==0){
               ans.push_back(v); 
            }
            return;
        }
        if(ind>9) return;
        
        v.push_back(ind);
        helper(ans,v,n,target-ind,ind+1,k-1);
        v.pop_back();
        
        
        helper(ans,v,n,target,ind+1,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int target = n;
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,v,n,target,1,k);
        return ans;
    }
};
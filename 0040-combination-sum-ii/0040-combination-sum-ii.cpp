class Solution {
public:
     void helper(vector<vector<int>>&ans,vector<int>& v,vector<int>& candidates, int target,int ind){
       
        if(ind==candidates.size()){
            if(target==0){
            ans.push_back(v); 
           }
            return;
        }
        if(candidates[ind]<=target){
        v.push_back(candidates[ind]);
        helper(ans,v,candidates,target-candidates[ind],ind+1);
        v.pop_back();
        }
         while(ind+1<candidates.size() && candidates[ind]==candidates[ind+1]) ind++;
        helper(ans,v,candidates,target,ind+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>> ans;
        vector<int> v;
        helper(ans,v,candidates,target,0);
        return ans;
    }
};
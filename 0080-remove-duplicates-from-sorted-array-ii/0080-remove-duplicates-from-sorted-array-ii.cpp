class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> umpp;
            for(int i=0; i<nums.size(); i++){
                    umpp[nums[i]]++;
            }
            int k=0;
            for(auto it:nums){
                    if(umpp.find(it)!=umpp.end()){
                            if(umpp[it]>1){
                               nums[k++] = it;
                               nums[k++] = it;
                               umpp.erase(it);     
                            }else{
                               nums[k++] = it;
                               umpp.erase(it);  
                            }
                          
                    }
            }
            return k;
    }
};
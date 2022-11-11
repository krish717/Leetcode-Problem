class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, bool> umpp;
            for(int i=0; i<nums.size(); i++){
                    umpp[nums[i]] = true;
            }
            int k = 0;
            
            for(auto it:nums){
                    if(umpp.find(it)!=umpp.end()){
                            nums[k++] = it;
                            umpp.erase(it);
                    }
            }
            return k;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> um;
        
        for(int i=0; i<numbers.size(); i++){
           
                if(um.find(target-numbers[i])!=um.end()){
                    return {um[target-numbers[i]]+1,i+1};
                }else{
                    um[numbers[i]] = i;
                }
            }
        return {-1,-1};
    }
};
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=-1;
        int ind = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
           if(nums[i]>maxi){
               maxi = nums[i]; 
               ind = i;
           }
            
        }
        
        for(int i=0; i<n; i++){
            if(i!=ind){
                if(maxi<2*nums[i]) return -1; 
            }
           
        }
        return ind;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countzero=0,i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            if(nums[j]==0) countzero++;
             if(countzero<=k){
                ans = max(ans,j-i+1);
                j++;
            }else if(countzero>k){
                while(countzero>k){
                    if(nums[i]==0) 
                    countzero--;
                    i++;
                }
                j++;

            }
            
        }
        return ans;
    }
};
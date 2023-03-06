class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        double ans = -1e9;
        int n = nums.size();
      
        double sum=0;
        double avg = 0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                 avg = sum/k;
                if(avg>ans) ans = avg;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
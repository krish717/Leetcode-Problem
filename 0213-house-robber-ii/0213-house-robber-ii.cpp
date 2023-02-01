class Solution {
public:
     int houseRobber1(vector<int>& nums) {
        //Tabulation
        int n = nums.size();
        
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int first = nums[i];
            if(i>1)
            first += prev2;
            int second = 0 + prev;
            int curr =  max(first, second);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> arr1;
        for(int i=1; i<n; i++){
            arr1.push_back(nums[i]);
        }
        vector<int> arr2;
        for(int i=0; i<n-1; i++){
            arr2.push_back(nums[i]);
        }
        int f = houseRobber1(arr1);
        int s = houseRobber1(arr2);
        return max(f,s);
    }
};
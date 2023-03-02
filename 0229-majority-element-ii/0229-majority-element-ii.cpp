class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1=-1,nums2=-1,c1=0,c2=0;
        int n = nums.size();
        int k = n/3;
        for(int i=0; i<n; i++){
            if(nums1==nums[i]) c1++;
            else if(nums2==nums[i]) c2++;
            else if(c1==0){
                nums1 = nums[i];
                c1=1;
            }else if(c2==0){
                nums2 = nums[i];
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0; i<n; i++){
            if(nums1==nums[i]) c1++;
             else if(nums2==nums[i]) c2++;
        }
        vector<int> v;
        if(c1>k) v.push_back(nums1);
         if(c2>k) v.push_back(nums2);
        return v;
    
    // vector<int> res;
    // if(c1 > k) res.push_back(nums1);
    // if(c2 > k) res.push_back(nums2);
    // return res;
    }
};
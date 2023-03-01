class Solution {
public:
    void merge(vector<int>& nums,int s,int mid,int h){
        vector<int> temp;
        int left = s;
        int right = mid+1;
        while(left<=mid && right<=h){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(nums[right]);
            right++;
        }
        int m=0;
        for(int i=s; i<=h; i++){
            nums[i] = temp[m++];
        }
    }
    void mergeSort(vector<int>& nums,int l,int h){
        if(l>=h) return;
        int mid = l+(h-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
    vector<int> sortArray(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        mergeSort(nums,l,h);
        return nums;
    }
};
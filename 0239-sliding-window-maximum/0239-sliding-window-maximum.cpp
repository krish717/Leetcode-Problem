class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> d;
        vector<int> ans;
        int n = arr.size();
        int i=0,j=0;
        while(j<n){
            while(d.size()>0 && d.back()<arr[j]){
                d.pop_back();
            }
            d.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans.push_back(d.front());
                if(arr[i]==d.front()) d.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};
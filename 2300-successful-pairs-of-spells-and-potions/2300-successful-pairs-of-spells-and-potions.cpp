class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(),m = potions.size();
        vector<int> v;
        sort(potions.begin(),potions.end());
        for(int i=0; i<n; i++){
            long long num = spells[i];
            int left = 0,right=m-1;
            while(left<=right){
                int mid = (left+right)/2;
                if(num*potions[mid]>=success){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            v.push_back(m-left);
        }
        return v;
    }
};
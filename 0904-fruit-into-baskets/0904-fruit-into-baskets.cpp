class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2;
        int n = fruits.size();
        int i=0,j=0,maxi=INT_MIN;
        unordered_map<int,int> mp;
        if(n==1) return 1;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<k) j++;
            else if(mp.size()==k){
                maxi = max(maxi,j-i+1);
                j++;
            }else if(mp.size()>k){
                while(mp.size()>k){
                      mp[fruits[i]]--;
                      if(mp[fruits[i]]==0){
                          mp.erase(fruits[i]);
                      }
                      i++;
                }
                j++;
            }
            
        }
         if(mp.size()==1){
            auto it = mp.begin();
        return it->second;
        }
        return maxi;
    }
};
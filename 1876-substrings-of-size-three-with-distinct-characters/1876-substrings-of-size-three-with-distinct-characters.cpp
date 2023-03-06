class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=0;
        int n = s.size();
        int ans=0;
        int k=3;
        unordered_map<char,int> um;
       
        while(j<n){
            um[s[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(um.size()==k){
                    ans++;
                    if(um.find(s[i])!=um.end())
                    um.erase(s[i]);
                         i++;
                         j++;  
                }else{
                     um[s[i]]--;
                     if(um[s[i]] == 0) um.erase(s[i]);
                     i++;
                     j++;
                }   
            }     
        }
        return ans;
    }
};
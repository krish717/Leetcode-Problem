class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int i=0,j=0;
        unordered_map<char,int> um;
        for(int i=0; i<p.size(); i++) um[p[i]]++;
        int count = um.size();
         vector<int> ans;
        while(j<s.size()){
            if(um.find(s[j])!=um.end()){
                um[s[j]]--;
                if(um[s[j]]==0) count--;
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(count==0) ans.push_back(i);
                if(um.find(s[i])!=um.end()){
                    um[s[i]]++;
                    if(um[s[i]]==1) count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
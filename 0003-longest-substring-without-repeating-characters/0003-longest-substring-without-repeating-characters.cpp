class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            um[s[j]]++;
            if(um.size()==j-i+1){
                ans = max(ans,j-i+1);
                j++;
            }else if(um.size()<j-i+1){
                while(um.size()<j-i+1){
                    um[s[i]]--;
                    if(um[s[i]]==0) um.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
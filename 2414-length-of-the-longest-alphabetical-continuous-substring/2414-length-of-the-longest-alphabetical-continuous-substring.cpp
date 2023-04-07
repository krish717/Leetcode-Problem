class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=0,count=1;
        for(int i=1; i<s.size(); i++){
            if(s[i-1]+1==s[i]) count++;
            else{
                ans = max(count,ans);
                count=1;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};
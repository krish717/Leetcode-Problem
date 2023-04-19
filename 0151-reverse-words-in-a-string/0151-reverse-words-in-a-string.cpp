class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0,n=s.size();
        string ans = "";
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            j=i;
            while(j<n && s[j]!=' ') j++;
            string substring = s.substr(i,j-i);
            if(ans.size()==0) ans=substring;
            else ans = substring + ' ' + ans;
            i=j;
            
        }
        return ans;
    }
};
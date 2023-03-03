class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int n = haystack.size();
        while(i<n){
            int k=i;
            int j=0;
            while(j<needle.size() && haystack[i]==needle[j]){
                i++;
                j++;
            }
            // string  a = haystack.substr(k, needle.size());
            
            if(haystack.substr(k, needle.size())==needle) return k;
            i=k+1;
            
        }
        return -1;
    }
};
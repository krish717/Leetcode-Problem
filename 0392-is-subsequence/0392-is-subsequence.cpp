class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k=0;
        for(int i=0; i<t.size(); i++){
            if(s[k]==t[i]) k++;
        }
        return k==s.size();
    }
};
class Solution {
public:
    string toLowerCase(string s) {
            string s1 = "";
        for(int i=0; i<s.size(); i++){
               s1+=tolower(s[i]);
        }
            return s1;
    }
};
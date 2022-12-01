class Solution {
public:
    bool halvesAreAlike(string s) {
        int cn1 = 0, cn2 = 0;
        for(int i=0;i<s.size()/2;i++){
            char ch = s[i];
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') cn1++;
            else if(ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') cn1++;
        }
        for(int i=s.size()/2;i<s.size();i++){
            char ch = s[i];
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') cn2++;
            else if(ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') cn2++;
        }
        return cn1 == cn2;
    }
};
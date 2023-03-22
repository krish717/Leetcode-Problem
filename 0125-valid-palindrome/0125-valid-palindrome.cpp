class Solution {
public:
    
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(isalnum(s[i])==false && i<j) i++;
            while(isalnum(s[j])==false && i<j) j--;
            if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }else{
                return 0;
            }
        }
        return 1;
    }
};
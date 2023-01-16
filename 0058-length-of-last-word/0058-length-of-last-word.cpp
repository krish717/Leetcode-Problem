class Solution {
public:
    int lengthOfLastWord(string s) {
            int k=0;
            for(int i=0; i<s.size(); i++){
                    if(s[i]!=' ') k=i;
            }
           int count=0;
            for(int i=k; i>=0; i--){
                   
                    if(s[i]==' ') break;
                    else count++;
            }
            return count;
    }
};
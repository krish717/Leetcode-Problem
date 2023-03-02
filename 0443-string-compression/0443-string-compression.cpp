class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0; 
        int ansIndex=0;
        int n=chars.size();
        while(i<n){
            int j=i; 
            while(j<n && chars[j]==chars[i]) j++;
            chars[ansIndex++] = chars[i];
            int count = j-i;
            if(count>1){
                string ch = to_string(count);
                for(char c:ch){
                    chars[ansIndex++] = c;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};
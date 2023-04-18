class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int i = 0;
        int ans = 0;
        while(i<n){
            string s2 = word.substr(i,2);
            if(word.substr(i,3)=="abc"){
                i+=3;
            }else if(s2=="ab" || s2=="ac" || s2=="bc"){
                i+=2;
                ans+=1;
            }else{
                i+=1;
                ans+=2;
            }
        }
        return ans;
    }
};
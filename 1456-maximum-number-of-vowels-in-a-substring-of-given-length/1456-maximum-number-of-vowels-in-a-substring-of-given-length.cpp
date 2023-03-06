class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0; 
        int i=0,j=0;
        int n = s.size();
        vector<char> v;
        while(j<n){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                v.push_back(s[j]);
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(v.size()>count){
                    count=v.size();
                }
                if(!v.empty() && s[i]==v[0]){
                 v.erase(v.begin());
                }
                i++;
                j++;
            }
        }
        return count;
    }
};
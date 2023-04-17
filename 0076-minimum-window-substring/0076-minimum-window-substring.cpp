class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(auto it:t) mp[it]++;
        int length = INT_MAX,count=mp.size(),i=0,j=0,n=s.size(),start=0;
        
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            while(count==0){
                if(length > j-i+1){
                    length = min(length,j-i+1);
                    start = i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                if(mp[s[i]]==1) count++;

                }
                i++;
            }
            j++;
        }
        return length == INT_MAX ? "" : s.substr(start, length);
            
    }
};
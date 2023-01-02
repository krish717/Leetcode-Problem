class Solution {
public:
    bool wordPattern(string p, string s) {
            vector<string> v;
            string x;
            map<string,int> mp1;
            for(int i=0; i<=s.size(); i++){
                    if(s[i]==' ' || i==s.size()){
                            v.push_back(x);
                            mp1[x]++;
                            x="";
                            
                    }else{
                            x+=s[i];
                    }
            }
            
            if(p.size()!=v.size()) return false;
            map<char,string> mp2;
            for(int i=0; i<v.size(); i++){
                    if(mp2.find(p[i])==mp2.end()){
                            mp2[p[i]] = v[i];
                    }else{
                            if(mp2[p[i]]!=v[i]) return false;
                    }
            }
            if(mp1.size()!=mp2.size()) return false;
            return true;
            
    }
};
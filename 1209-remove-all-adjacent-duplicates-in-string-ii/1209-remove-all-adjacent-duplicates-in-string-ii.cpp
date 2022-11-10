class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, short>> v;
            for(auto it:s){
                    if(v.empty() || v.back().first!=it){
                            v.push_back({it,0});
                    }
                    if(++v.back().second==k){
                            v.pop_back();
                    }
            }
            string res;
           for (auto& p : v) res += string(p.second, p.first);
             
            return res;
    }
};
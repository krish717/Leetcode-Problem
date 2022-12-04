class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26), v2(26);
        for(auto c : word1) v1[c-'a']++;
        for(auto c : word2) v2[c-'a']++;
        set<char> st(word1.begin(),word1.end());
        for(auto c : word2) if(!st.count(c)) return false;
        map<int,int> mp;
        for(auto v : v1) mp[v]++;
        for(auto v : v2) if(--mp[v] == 0) mp.erase(v);
        return mp.empty();
    }
};
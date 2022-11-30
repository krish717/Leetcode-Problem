class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto i : arr) mp[i]++;
        set<int> st;
        for(auto [k,v] : mp){
            if(st.count(v)) return false;
            st.insert(v);
        }
        return true;
    }
};
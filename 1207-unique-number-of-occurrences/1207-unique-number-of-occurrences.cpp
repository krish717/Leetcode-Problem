class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
            for(int i=0; i<arr.size(); i++){
                    um[arr[i]]++;
            }
            set<int> ans;
            for(auto it=um.begin(); it!=um.end(); it++){
                  ans.insert(it->second);  
            }
            
            return (ans.size()==um.size());
    }
};
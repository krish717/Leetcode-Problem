class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
            for(auto it:s){
                    if(it==ans.back()) ans.pop_back();
                    else ans+=it;
            }
            return ans;
    }
};
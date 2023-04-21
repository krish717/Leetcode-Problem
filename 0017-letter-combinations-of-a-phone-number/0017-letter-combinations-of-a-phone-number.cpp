class Solution {
public:
    void solve(string &digits,vector<string> &ans,string s,int ind,string mapping[]){
        if(ind>=digits.size()){
            ans.push_back(s);
            return;
        }
        
        int number = digits[ind]-'0';
        string value = mapping[number];
        
        for(int i=0; i<value.size(); i++){
            s.push_back(value[i]);
            solve(digits,ans,s,ind+1,mapping);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        int ind = 0;
        solve(digits,ans,s,ind,mapping);
        return ans;
    }
};
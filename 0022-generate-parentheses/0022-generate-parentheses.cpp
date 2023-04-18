class Solution {
public:
    void fun(int n, vector<string> &ans,int open,int close,string s){
         if(open==0 && close==0){
             ans.push_back(s);
             return;
         }
         if(open!=0) fun(n,ans,open-1,close,s+"(");
         if(close>open) fun(n,ans,open,close-1,s+")");
    }
    vector<string> generateParenthesis(int n) {
         vector<string> ans;
        fun(n,ans,n,n,"");
        return ans;
    }
};
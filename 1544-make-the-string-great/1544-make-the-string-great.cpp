class Solution {
public:
    string makeGood(string s) {
        // stack<char> st;
        //     for(int i=0; i<s.size(); i++){
        //             if(st.empty()){
        //                     st.push(s[i]);
        //                     continue;
        //             }
        //             if(abs(st.top()-s[i])==32){
        //                     st.pop();
        //             }else{
        //                  st.push(s[i]);   
        //             }
        //     }
        //     string ans = "";
        //     while(!st.empty()){
        //             ans=st.top()+ans;
        //             st.pop();
        //     }
        //     return ans;
            int st = 0;
            while(st!=s.size()){
                    st = s.size();
                    for(int i=0; i<s.size(); i++){
                            if(abs(s[i]-s[i+1])==32){
                                    s = s.substr(0,i) + s.substr(i+2);
                            }
                    }
            }
            return s;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> s;
       for(int i=0; i<tokens.size(); i++){
              if(tokens[i]=="+"){
                      int x = s.top();
                      s.pop();
                      int y = s.top();
                      s.pop();
                      int z = x+y;
                      s.push(z);
              }else if(tokens[i]=="-"){
                      int x = s.top();
                      s.pop();
                      int y = s.top();
                      s.pop();
                      int z = y-x;
                      s.push(z);
              }else if(tokens[i]=="/"){
                      int x = s.top();
                      s.pop();
                      int y = s.top();
                      s.pop();
                      int z = y/x;
                      s.push(z);
                      
              }else if(tokens[i]=="*"){
                      long x = s.top();
                      s.pop();
                      long y = s.top();
                      s.pop();
                      long z = x*y;
                      s.push(z);
              }else{
                      s.push(stoi(tokens[i]));
              }
       } 
            return s.top();
    }
};
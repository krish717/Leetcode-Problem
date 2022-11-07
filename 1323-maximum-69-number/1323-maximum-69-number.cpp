class Solution {
public:
    int maximum69Number (int num) {
        string snum = to_string(num);
            for(int i=0; i<snum.size(); i++){
                    if(snum[i]=='6'){
                           snum[i]='9';
                            break;
                    }
            }
            return stoi(snum);
    }
};
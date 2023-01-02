class Solution {
public:
        void addInto(string &ans,string x){
                string s="";
                for(int i=0; i<x.size(); i++){
                        if(i==0){
                                s+=toupper(x[0]);
                        }else{
                                s+=tolower(x[i]);
                        }
                }
                ans+=" ";
                ans+=s;
                
        }
    string capitalizeTitle(string title) {
            string x="";
            string ans;
        for(int i=0; i<=title.size(); i++){
                if(title[i]==' ' || i==title.size()){
                        if(x.size()>2){
                            addInto(ans,x);    
                        }else if(x.size()==1){
                                string s5="";
                                s5+=" ";
                                s5+=tolower(x[0]);
                                
                                ans+=s5; 
                        }else{
                                string s6="";
                                s6+=" ";
                                s6+=tolower(x[0]);
                                s6+=tolower(x[1]);
                                
                                ans+=s6;
                        }
                        x = "";
                }else{
                        x+=title[i];
                }
        }
            
           string mainAns = "";
            for(int i=1; i<ans.size(); i++){
                  mainAns+=ans[i];
            }
            return mainAns;
    }
};
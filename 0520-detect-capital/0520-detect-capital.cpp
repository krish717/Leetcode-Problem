class Solution {
public:
        bool Allcaps(string &word){
                for(int i=0;i<word.size(); i++){
                      if(islower(word[i])) return false;
                }
                return true;
        }
        bool Allletter(string word){
                for(int i=0;i<word.size(); i++){
                      if(isupper(word[i])) return false;
                }
                return true;
        }
        bool oneCaps(string word){
                for(int i=0;i<word.size(); i++){
                        if(islower(word[0])) return false;
                        if(i>0){
                           if(isupper(word[i])) return false;     
                        }
                      
                }
                return true;
        }
    bool detectCapitalUse(string word) {
        return Allcaps(word) || Allletter(word) || oneCaps(word);
    }
};
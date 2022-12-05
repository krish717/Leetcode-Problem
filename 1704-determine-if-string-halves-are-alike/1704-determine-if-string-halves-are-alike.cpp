class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int count2 = 0;
            for(int i=0; i<s.size()/2; i++){
               char ch = s[i];
               if(ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u') count1++;
               else if(ch=='A' || ch=='E' || ch=='I' || ch=='O' ||ch=='U') count1++;  
            }
            
             for(int i=s.size()/2; i<s.size(); i++){
               char ch = s[i];
               if(ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u') count2++;
               else if(ch=='A' || ch=='E' || ch=='I' || ch=='O' ||ch=='U') count2++;  
            }
            
            return (count1==count2);
    }
};
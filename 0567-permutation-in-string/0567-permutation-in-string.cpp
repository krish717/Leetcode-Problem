class Solution {
public:
    bool checkInclusion(string pat, string txt) {
       
         int ans=0,i=0,j=0;
	    int n = txt.size();
	    unordered_map<char,int> um;
	    int k=pat.size();
	    for(int i=0; i<k; i++){
	         um[pat[i]]++;
	    }
	    int count = um.size();
	    while(j<n){
	        if(um.find(txt[j])!=um.end()){
	            um[txt[j]]--;
	            if(um[txt[j]]==0) count--;
	        }
	        
	        if(j-i+1<k) j++;
	        else{
	            if(count==0){
                     ans++;
                    break;
                }
	            if(um.find(txt[i])!=um.end()){
	                um[txt[i]]++;
	                if(um[txt[i]]==1) count++;
	            }
	            i++;
	            j++;
	        }
	    }
        if(ans==0) return false;
        else return true;
	    
    }
};
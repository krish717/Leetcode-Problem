class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
            stack<pair<int,int>> s;
            for(int i=temperatures.size()-1; i>=0; i--){
                   if(s.size()==0){
                           ans.push_back(0);
                   }else if(!s.empty() && s.top().first>temperatures[i]){
                           ans.push_back(1);
                   }else if(!s.empty() && s.top().first<=temperatures[i]){
                           while(!s.empty() && s.top().first<=temperatures[i]){
                                   s.pop();
                           }
                           if(s.size()==0) ans.push_back(0);
                           else ans.push_back(s.top().second-i);
                   }
                    s.push({temperatures[i],i});
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};
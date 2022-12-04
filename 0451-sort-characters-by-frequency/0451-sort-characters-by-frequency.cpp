class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int> umpp;
            for(int i=0; i<s.size(); i++){
                    umpp[s[i]]++;
            }
            
            priority_queue<pair<int, char>> pq;
            for(auto it: umpp){
                    pq.push({it.second,it.first});
            }
            string output = "";
            while(!pq.empty()){
                   
                    int freq = pq.top().first;
                    int cha  = pq.top().second;
                   while(freq>0){
                           output.push_back(cha);
                           freq--;
                   }
                         pq.pop();    
                    
            }
            return output;
    }
};
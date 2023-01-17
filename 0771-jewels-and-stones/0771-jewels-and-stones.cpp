class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> um;
            for(int i=0; i<stones.size(); i++){
                    um[stones[i]]++;
            }
            int count=0;
            for(int i=0; i<jewels.size(); i++){
                    if(um.find(jewels[i])!=um.end()){
                            count +=um[jewels[i]];
                            um.erase(jewels[i]);
                    }
            }
            return count;
    }
};
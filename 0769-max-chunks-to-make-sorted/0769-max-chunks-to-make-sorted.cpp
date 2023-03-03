class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0;
        int chunk = 0;
        for(int i=0; i<arr.size(); i++){
            maxVal = max(maxVal,arr[i]);
            if(maxVal==i) chunk++;
        }
        return chunk;
    }
};
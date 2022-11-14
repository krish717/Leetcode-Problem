class Solution {
public:
    void dfs(int i,vector<vector<int>> &stones,vector<bool> &vis){
        vis[i] = true;
        for(int j=0;j<stones.size();j++){
            if(vis[j]) continue;
            if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                dfs(j,stones,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n);
        int remove = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            remove++;
            dfs(i,stones,vis);
        }
        return n-remove;
    }
};
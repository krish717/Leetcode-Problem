class Solution {
private:
    bool isCellEmpty(int row,int col,vector<vector<bool>> &vis,vector<vector<char>> &maze){
        if(row < 0 or col < 0 or row == maze.size() or col == maze[0].size()) return false;
        return maze[row][col] == '.' and !vis[row][col];
    }
    bool isExit(int row,int col,int m,int n){
        return row-1 < 0 or col-1 < 0 or row+1 == m or col+1 == n;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int path = -1;
        while(q.size()){
            int sz = q.size();
            path++;
            while(sz--){
                auto [row,col] = q.front(); q.pop();
                vis[row][col] = true;

                if(isExit(row,col,m,n) and path) return path;
                
                if(isCellEmpty(row+1,col,vis,maze)) q.push({row+1,col}), vis[row+1][col] = true;
                if(isCellEmpty(row-1,col,vis,maze)) q.push({row-1,col}), vis[row-1][col] = true;
                
                if(isCellEmpty(row,col-1,vis,maze)) q.push({row,col-1}), vis[row][col-1] = true;      
                if(isCellEmpty(row,col+1,vis,maze)) q.push({row,col+1}), vis[row][col+1] = true;
            }
        }
        return -1;
    }
};
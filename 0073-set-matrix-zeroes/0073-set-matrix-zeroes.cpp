class Solution {
public:
    void row(int i,vector<vector<int>>& matrix){
        for(int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j]!=0) matrix[i][j] = -11;
        }
    }
     void col(int j,vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][j]!=0) matrix[i][j] = -11;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row(i,matrix);
                    col(j,matrix);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==-11) matrix[i][j] = 0;
            }
        }
    }
};
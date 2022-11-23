class Solution {
public:
    bool checkSubgrid(vector<vector<char>> &board){
        for(int i=0;i<9;i+=3){
            int j=0;
            while(j < 9){
                int row = i, col = j;
                unordered_set<char> st;
                for(int x=row;x<i+3;x++){                    
                    for(int y=col;y<j+3;y++){                        
                        char val = board[x][y];                        
                        if(val >= '1' and val <= '9'){
                            if(st.find(val) != st.end()) return false;
                            st.insert(val);
                        }                        
                    }                    
                }               
                j += 3;
            }
        }  
        return true;
    }
        
    bool rowCheck(int i,vector<vector<char>> &board,unordered_set<char> st){
        for(int j=0;j<9;j++){
            char val = board[i][j];
            if(val >= '1' and val <= '9'){
                if(st.find(val) != st.end()) return false;
                st.insert(val);    
            }
        } 
        return true;
    }
    
    bool colCheck(int i,vector<vector<char>> &board,unordered_set<char> st){
        for(int j=0;j<9;j++){
            char val = board[j][i];
            if(val >= '1' and val <= '9'){
                if(st.find(val) != st.end()) return false;
                st.insert(val);    
            }
        }  
        return true;
    }
    
    bool checkRowAndCol(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            unordered_set<char> st;
            
            bool validRow = rowCheck(i,board,st);
            bool validCol = colCheck(i,board,st);
            
            if(!validRow or !validCol) return false;
        }    
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkSubgrid(board) and checkRowAndCol(board);
    }
};
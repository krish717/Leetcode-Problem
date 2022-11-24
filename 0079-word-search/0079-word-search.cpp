class Solution {
public:
    bool helper(int i,int j,int n,int m,vector<vector<char>>& board, string &word,int k){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]) return false;
            
         char ch = board[i][j];
         board[i][j] = '#';
         bool op1 = helper(i+1,j,n,m,board,word,k+1);
         bool op2 = helper(i,j+1,n,m,board,word,k+1);
         bool op3 = helper(i-1,j,n,m,board,word,k+1);
         bool op4 = helper(i,j-1,n,m,board,word,k+1);
         // bool temp = false;  
         // for(int ind=0; ind<4; ind++){
         //         temp = temp ||  helper(i+di[ind],j+dj[ind],n,m,board,word,k+1,di,dj);
         // }   
         board[i][j] = ch;  
         return op1 || op2 || op3 || op4;
         // return temp;   
    }
                
               

    bool exist(vector<vector<char>>& board, string word) {
         int n = board.size();
         int m = board[0].size();   
    // vector<vector<int>> vis(n, vector<int>(m,0));
    int di[] = {+1,0,0,-1};
    int dj[] = {0,-1,1,0};
   
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(word[0]==board[i][j]){
               if(helper(i,j,n,m,board,word,0)) return true;
           }
        }
    }
  
     return false;
    }
};
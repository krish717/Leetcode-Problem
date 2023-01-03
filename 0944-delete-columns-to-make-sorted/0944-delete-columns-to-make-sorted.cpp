class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
            int delete_row = 0;
            
            for(int j=0; j<col; j++){
                    for(int i=1; i<row; i++){
                           if(strs[i][j]<strs[i-1][j]){
                               delete_row++;
                               break;    
                           } 
                    }
            }
            return delete_row;
            
    }
};
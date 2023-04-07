class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int top = 0,left=0,right=n-1,bottom=n-1,currValue=1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                ans[top][i]=currValue;
                currValue++;
            }
            top++;
            for(int i=top; i<=bottom; i++){
                ans[i][right]=currValue;
                currValue++;
            }
            right--;
            if(top<=bottom){
            for(int i=right; i>=left; i--){
                ans[bottom][i]=currValue;
                currValue++;
            }
            bottom--;
            }
            if(left<=right){
            for(int i=bottom; i>=top; i--){
                ans[i][left]=currValue;
                currValue++;
            }
            left++;
            }
        }
        return ans;
    }
};
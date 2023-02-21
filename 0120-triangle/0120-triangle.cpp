class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        int i=0,j=0;
        vector<int> prev(n);
        vector<int> curr(n);
        for(int j=0; j<n; j++){
            prev[j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
              
            for(int j=i; j>=0; j--){
                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];
               curr[j] = min(d,dg);
            }
            prev = curr;
        }
        return prev[0];
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);
            //base case
            for(int j=0; j<n; j++){
                    prev[j] = triangle[n-1][j]; 
            }
            
            for(int i=n-2; i>=0; i--){
                    vector<int> curr(n);
                    for(int j=i; j>=0; j--){
                            int ans1 = triangle[i][j] + prev[j];
                            int ans2 = triangle[i][j] + prev[j+1];
                            curr[j] = min(ans1,ans2);
                    }
                    prev = curr;
            }
            return prev[0];
    }
};
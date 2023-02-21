class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        // dp[0][0] = 1;
         for(int i=0; i<m; i++){
             vector<int> curr(n,0);
             for(int j=0; j<n; j++){
                 if(i==0 && j==0)
                    curr[0]=1;
                     else{
                         int pick = 0,notpick=0;
                         if(i>0)
                          pick +=  prev[j];
                         if(j>0)
                          notpick +=  curr[j-1];
                         curr[j] = pick + notpick;
                     }
              
             }
                prev = curr;
         }
        return prev[n-1];
    }
};
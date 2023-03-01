class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>> prev(2,vector<int>(k+1,0));
       vector<vector<int>> curr(2,vector<int>(k+1,0));
        // return helper(0,1,2,prices,dp);
        
        //Tabulation
        //base case
        for(int i=0; i<n; i++){
            for(int buy=0; buy<2; buy++){
                prev[buy][0] = 0;
            }
        }
        for(int buy=0; buy<2; buy++){
            for(int cap=0; cap<k; cap++){
               prev[buy][cap] = 0;
            }
        }
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=1; buy>=0; buy--){
                for(int cap=k; cap>=1; cap--){
                    if(buy==1){
                     curr[buy][cap] = max(-prices[ind]+prev[0][cap],(0+prev[1][cap]));
             }else{
                     curr[buy][cap] = max(prices[ind]+prev[1][cap-1],(0+prev[0][cap]));
                }
            }
        }
            prev = curr;
    }
    return prev[1][k];
    }
};
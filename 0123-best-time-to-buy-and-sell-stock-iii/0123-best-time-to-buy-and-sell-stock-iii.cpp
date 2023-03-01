class Solution {
public:
//     int helper(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
//         if(cap==0) return 0;
//         if(ind==prices.size()) return 0;
//         if(buy==1){
//            return  dp[ind][buy][cap] = max(-prices[ind]+helper(ind+1,0,cap,prices,dp),(0+helper(ind+1,1,cap,prices,dp)));
//         }else{
//            return dp[ind][buy][cap] = max(prices[ind]+helper(ind+1,1,cap-1,prices,dp),(0+helper(ind+1,0,cap,prices,dp)));
//         }
        
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>> prev(2,vector<int>(3,0));
       vector<vector<int>> curr(2,vector<int>(3,0));
        // return helper(0,1,2,prices,dp);
        
        //Tabulation
        //base case
        for(int i=0; i<n; i++){
            for(int buy=0; buy<2; buy++){
                prev[buy][0] = 0;
            }
        }
        for(int buy=0; buy<2; buy++){
            for(int cap=0; cap<2; cap++){
               prev[buy][cap] = 0;
            }
        }
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=1; buy>=0; buy--){
                for(int cap=2; cap>=1; cap--){
                    if(buy==1){
                     curr[buy][cap] = max(-prices[ind]+prev[0][cap],(0+prev[1][cap]));
             }else{
                     curr[buy][cap] = max(prices[ind]+prev[1][cap-1],(0+prev[0][cap]));
                }
            }
        }
            prev = curr;
    }
    return prev[1][2];
};
};
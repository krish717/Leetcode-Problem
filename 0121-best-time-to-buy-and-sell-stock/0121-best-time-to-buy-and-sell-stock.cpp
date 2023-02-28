class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int maxprofit=0,mini=prices[0];
        for(int i=1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            maxprofit = max(maxprofit,cost);
                mini = min(mini,prices[i]);
        }
        return maxprofit;
    }
};
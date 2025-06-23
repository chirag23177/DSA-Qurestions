class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int maxProfit = 0;

        for(int i = 1; i<prices.size(); i++){
            int j = i-1;
            if(prices[j] < prices[i]){
                minBuy = min(minBuy, prices[j]);
            }
            int profit = prices[i] - minBuy;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
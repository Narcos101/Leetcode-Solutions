class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costPrice = prices[0];
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            costPrice = min(costPrice,prices[i]);
            profit = max(profit, prices[i]-costPrice);
        }    
        return profit;
    }
};
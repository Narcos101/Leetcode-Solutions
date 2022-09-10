class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stock = prices[0];
        int n = prices.size();
        int ans = 0;
        for(int i = 1; i < n;i++){
            if(stock < prices[i]){
                ans = ans + (prices[i]-stock);
                
            }
            stock = prices[i];
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return calc(prices,dp,1,cap,0);
    }
    
    int calc(vector<int>&prices, vector<vector<vector<int>>>&dp,int buy,int cap,int i){
        if(i == prices.size()){
            return 0;
        }
        if(cap == 0){
            return 0;
        }
        if(dp[i][buy][cap] != -1){
            return dp[i][buy][cap];
        }
        if(buy){
            int buys = -prices[i] + calc(prices,dp,1-buy,cap,i+1);
            int notbuys = calc(prices,dp,buy,cap,i+1);
             return dp[i][buy][cap] = max(buys,notbuys);
        }
        else{
            int sells = prices[i] + calc(prices,dp,1-buy,cap-1,i+1);
            int notsells = calc(prices,dp,buy,cap,i+1);
             return dp[i][buy][cap] = max(sells,notsells);
        }
    }  
};
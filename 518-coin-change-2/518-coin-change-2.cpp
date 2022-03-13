class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1,-1));
        return calc(amount,coins,0,dp);
    }
    
    int calc(int amount, vector<int>&coins, int index,vector<vector<int>>&dp){
        if(index >= coins.size() || amount < 0){
            return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        if(amount == 0){
            return 1;
        }
        return dp[index][amount] = calc(amount-coins[index],coins,index,dp) + calc(amount,coins,index+1,dp);
    }
};
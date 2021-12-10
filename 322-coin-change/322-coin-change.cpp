class Solution {
public:
    
    int coinChange(vector<int>& coins, int sum) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(sum+1,-1));
        int ans = calc(coins.size(),coins,sum,dp);
        if(ans == INT_MAX-1){
            return -1;
        }
        else{
            return ans;
        }
    }
    
    
    int calc(int n,vector<int>& coins,int sum,vector<vector<int>>&dp){
        if(n == 0 || sum == 0){
            return sum == 0 ? (0):(INT_MAX-1);
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        if(sum < coins[n-1]){
            return dp[n][sum] = calc(n-1,coins,sum,dp);
        }
        else{
            return dp[n][sum] = min(1 + calc(n,coins,sum-coins[n-1],dp), calc(n-1,coins,sum,dp));
        }
    }
};
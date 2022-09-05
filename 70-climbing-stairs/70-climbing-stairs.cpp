class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return calc(n,dp);
    }
    
    
    int calc(int n, vector<int>&dp){
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int con1 = 0;
        int con2 = 0;
        if(n >= 1){
            con1 = calc(n-1,dp);
        }
        if(n >= 2){
            con2 = calc(n-2,dp);
        }
        return dp[n] = con1 + con2;
    }
};
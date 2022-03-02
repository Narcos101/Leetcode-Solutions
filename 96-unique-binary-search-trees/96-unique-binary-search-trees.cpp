class Solution {
public:
    int numTrees(int n) {
        // 1 1 2 3 5 
        // 5 - COC4 + C1C3 + C2C2 + C3C1 + C4CO
        // 2 - COC1 + C1C0
        // 3 - COC2 + C1C1 + C2C0
        
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        if(n <= 1){
            return 1;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};
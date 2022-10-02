class Solution {
public:
    int mod = 1e9+7;
    int numRollsToTarget(int n, int nk, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= n;i++){
            for(int k = 1; k <= target;k++){
                int ans = 0;
                for(int j = 1; j <= nk;j++){
                    if(j <= k){
                        ans = (ans % mod + dp[i-1][k-j] % mod) % mod;
                    }
                }
                dp[i][k] = ans;
            }
        } 
        return dp[n][target];
    }
};    
    
//     int calc(int n,int k,int target,vector<vector<int>>&dp){
//         if(n == 0){
//             if(target == 0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(dp[n][target] != -1){
//             return dp[n][target];
//         }
//         int ans = 0;
        
//         return dp[n][target] = ans;
//     }

class Solution {
public:
    int knightDialer(int n) {
        int mod = 1000000007;
        vector<vector<int>>paths={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}}; 
        vector<vector<int>>dp(n+1,vector<int>(10,0));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 9; j++){
                if(i == 1){
                    dp[i][j] = 1;
                }        
                for(auto k:paths[j]){
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod; 
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= 9; i++){
            ans = (ans + dp[n][i]) % mod;    
        }
        return ans;
    }
};
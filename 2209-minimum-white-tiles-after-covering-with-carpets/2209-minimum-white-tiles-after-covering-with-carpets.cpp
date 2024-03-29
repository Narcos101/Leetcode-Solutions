class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        vector<int> dp(n,  0), ndp(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = (i ? dp[i-1] : 0) + floor[i] - '0';
        }
        for(int i = 1; i <= numCarpets; i++) {
            for(int j = 0; j < n; j++) {
                ndp[j] =  (j ? ndp[j-1]: 0) + floor[j] - '0';
                ndp[j] = (j < carpetLen) ? 0 : min(ndp[j], dp[j - carpetLen]);
            }
            dp = ndp;
        }
        return dp[n-1];
    }
};

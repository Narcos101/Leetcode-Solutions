class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int,unordered_map<int,unordered_map<int,int>>>mpp;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return calc(n,m,grid,k,0,0,0,dp);
    }
    
    int calc(int n,int m,vector<vector<int>>&grid,int k,int i,int j,int sum,vector<vector<vector<int>>>&dp){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return ((sum + grid[i][j]) % k == 0);
        }
        if(dp[i][j][sum] != -1){
            return dp[i][j][sum];
        }
        int ans = calc(n,m,grid,k,i+1,j,(sum + grid[i][j]) % k,dp) % mod;
        ans = ans + calc(n,m,grid,k,i,j+1,(sum + grid[i][j]) % k,dp) % mod;
        return dp[i][j][sum] = ans % mod;
    }
    
    
    
    
    
    
};
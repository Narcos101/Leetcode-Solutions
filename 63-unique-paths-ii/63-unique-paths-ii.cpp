class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int ans = 0;
        int m = og.size();
        int n = og[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return calc(m,n,ans,0,0,dp,og);
    }
    
    int calc(int m,int n, int&ans, int i, int j,vector<vector<int>>&dp,vector<vector<int>>&og){
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        if(i < 0 || i >= m || j < 0 || j >= n || og[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        return dp[i][j] = calc(m,n,ans,i+1,j,dp,og) + calc(m,n,ans,i,j+1,dp,og);
    }
};
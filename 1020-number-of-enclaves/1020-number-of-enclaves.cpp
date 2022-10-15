class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i = 0; i < m;i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                calc(n,m,0,i,grid,vis);
            }
            if(grid[n-1][i] == 1 && !vis[n-1][i]){
                calc(n,m,n-1,i,grid,vis);
            }
        }
        for(int i =0; i < n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
               calc(n,m,i,0,grid,vis); 
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                calc(n,m,i,m-1,grid,vis);
            }
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
    
    
    void calc(int n,int m,int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        if(dp[i][j] == 1 || grid[i][j] == 0){
            return;
        }
        dp[i][j] = 1;
        calc(n,m,i,j+1,grid,dp);
        calc(n,m,i+1,j,grid,dp);
        calc(n,m,i-1,j,grid,dp);
        calc(n,m,i,j-1,grid,dp);
    }
};
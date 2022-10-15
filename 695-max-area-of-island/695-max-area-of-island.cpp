class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        int maxans = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int ans = calc(grid,n,m,i,j,vis);
                    maxans = max(maxans,ans);
                }
            }
        }
        return maxans;
    }
    
    int calc(vector<vector<int>>&grid,int n,int m,int i, int j,vector<vector<int>>&vis){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j] == 1){
            return 0;
        }
        vis[i][j] = 1;
        return 1 + calc(grid,n,m,i+1,j,vis) + calc(grid,n,m,i-1,j,vis) + calc(grid,n,m,i,j-1,vis) + calc(grid,n,m,i,j+1,vis);
    }
};
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid2[i][j] == 1 && !vis[i][j]){
                    if(calc(i,j,n,m,grid1,grid2,vis)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    
    
    int calc(int i,int j,int n,int m,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&vis){
        if(i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] == 0 || vis[i][j] == 1){
            return true;
        }        
        if(grid1[i][j] == 0){
            return false;
        }
        vis[i][j] = 1;
        bool con1 = calc(i+1,j,n,m,grid1,grid2,vis);
        bool con2 = calc(i-1,j,n,m,grid1,grid2,vis);
        bool con3 = calc(i,j+1,n,m,grid1,grid2,vis);
        bool con4 = calc(i,j-1,n,m,grid1,grid2,vis);
        return con1 && con2 && con3 && con4;
    }
};
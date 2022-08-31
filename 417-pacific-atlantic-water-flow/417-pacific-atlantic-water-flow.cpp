class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>vis2(n,vector<int>(m,0));
        queue<pair<int,int>>q2;
        for(int i = 0; i < m;i++){
            q2.push({n-1,i});
            q.push({0,i});
        }
        for(int j = 1; j < n;j++){
            q2.push({j-1,m-1});
            q.push({j,0});
        }
        calc(q,vis,heights);
        calc(q2,vis2,heights);
        for(int i =0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(vis[i][j] == 1 && vis2[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void calc(queue<pair<int,int>>q,vector<vector<int>>&vis,vector<vector<int>>&heights){
        int n = heights.size();
        int m = heights[0].size();
        while(!q.empty()){
            auto nq = q.front();
            int f = nq.first;
            int s = nq.second;
            vis[f][s] = 1;
            q.pop();
            if(f-1 >= 0 && vis[f-1][s] == 0 && heights[f-1][s] >= heights[f][s]){
                q.push({f-1,s});
            }
            if(f+1 < n && vis[f+1][s] == 0 && heights[f+1][s] >= heights[f][s]){
                q.push({f+1,s});
            }
            if(s-1 >= 0 && vis[f][s-1] == 0 && heights[f][s-1] >= heights[f][s]){
                q.push({f,s-1});
            }
            if(s+1 < m && vis[f][s+1] == 0 && heights[f][s+1] >= heights[f][s]){
                q.push({f,s+1});
            }
        }
    }
};
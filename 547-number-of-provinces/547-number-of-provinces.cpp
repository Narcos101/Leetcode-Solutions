class Solution {
public:
    
    void calc(vector<int>adj[],vector<int>&vis,int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                calc(adj,vis,it);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& g) {
        int ans = 0;
        int n = g.size();
        vector<int>adj[n];
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[i].size(); j++){
                if(i == j){
                    continue;
                }
                else{
                    if(g[i][j] == 1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                calc(adj,vis,i);
                ans++;
            }
        }
        return ans;
    }
};
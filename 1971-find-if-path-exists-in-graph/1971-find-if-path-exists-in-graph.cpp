class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        // an easy way would be mark the adjacent nodes of every node and then traverse if the start and end of both the              nodes at the end are marked we can say that there is a path between them
        vector<int>adj[n];
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n+1,0);
        
        calc(start,adj,vis);
        if(vis[start] && vis[end]){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    void calc(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                calc(i,adj,vis);
            }
        }
    }
    
};
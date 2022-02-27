class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1){
            return 0;
        }
        queue<vector<int>>q;
        int finalState = (1 << graph.size()) - 1;
        vector<vector<int>>visited(graph.size(),vector<int>(finalState+1,0));
        for(int i = 0; i < graph.size(); i++){
            q.push({i,1 << i});
        }
        int shortestPath = 0;
        while(!q.empty()){
            shortestPath++;
            int n = q.size();
            for(int j = 0; j < n; j++){
                int index = q.front()[0];
                int state = q.front()[1];
                q.pop();    
                for(auto i: graph[index]){
                    int new_visited_state = state | 1 << i;
                    if(new_visited_state == finalState){
                        return shortestPath;
                    }
                    if(visited[i][new_visited_state] == 1){
                        continue;
                    }
                    visited[i][new_visited_state] = 1;
                    q.push({i,new_visited_state});
                }
            }
        }
        return -1;
    }
};
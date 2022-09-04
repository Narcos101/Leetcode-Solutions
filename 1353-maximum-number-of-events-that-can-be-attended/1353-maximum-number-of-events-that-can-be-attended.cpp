class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // [[1,2],[1,2],[3,3],[1,5],[1,5]]
        int n = events.size();
        sort(events.begin(),events.end());
        int i = 0;
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int d = 1; d <= 100000; d++){
            while(!pq.empty() && pq.top() < d){
                pq.pop();
            }
            
            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }
            
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
            
            if(pq.empty()&&i==n)
                break;

        }
        return ans;
    }
};
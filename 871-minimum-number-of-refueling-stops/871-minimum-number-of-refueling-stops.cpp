class Solution {
public:
    int minRefuelStops(int target, int curr, vector<vector<int>>& s) {
        priority_queue<int>pq;
        int res = 0;
        int n = s.size();
        int i = 0;
        for(res = 0; curr < target;res++){
            while(i < n && s[i][0] <= curr){
                pq.push(s[i++][1]);
            }
            if(pq.empty()){
                return -1;
            }
            curr += pq.top();
            pq.pop();
        }
        return res;
    }
};
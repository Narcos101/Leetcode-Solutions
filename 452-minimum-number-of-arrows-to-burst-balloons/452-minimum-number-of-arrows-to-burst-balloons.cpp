class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int temp = 0;
        int res = 1;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= intervals[temp][1]){
                if(intervals[i][1] < intervals[temp][1]){
                    intervals[temp][1] = min(intervals[i][1],intervals[temp][1]);
                }
            }
            else{
                res++;
                temp = i;
            }
        }
        return res;
    }
};
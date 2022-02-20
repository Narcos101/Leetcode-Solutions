class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>a,vector<int>b){
            return a[0]==b[0]?a[1] > b[1]:a[0] < b[0];
        });
        vector<int>tempInterval = intervals[0];
        int ans = 0;
        int n = intervals.size();
        for(int i =  1; i < n; i++){
            if(tempInterval[1] >= intervals[i][0] && tempInterval[1] >= intervals[i][1] && tempInterval[0] <= intervals[i][0] && tempInterval[0] <= intervals[i][1]){
                ans++;
            }
            else{
                tempInterval = intervals[i];
            }
        }
        
        // 1 1
        // 1 1 
        return n-ans;
    }
};
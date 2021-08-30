class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        sort(intervals.begin(),intervals.end());
        if(intervals.size() == 0){
            return mergedIntervals;
        }
        vector<int>tempInterval = intervals[0];
        for(auto i: intervals){
            if(i[0] <= tempInterval[1]){
                tempInterval[1] = max(tempInterval[1],i[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = i;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};
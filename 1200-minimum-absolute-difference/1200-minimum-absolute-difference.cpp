class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
            int minDiff = INT_MAX;
        vector<vector<int>> answer;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size()-1; ++i) {
        minDiff = min(minDiff, arr[i+1]-arr[i]);
    }

    for (int i = 0; i < arr.size()-1; ++i) {
        if (minDiff == arr[i+1] - arr[i]) {
            answer.push_back(vector<int>{arr[i], arr[i+1]});
        }
    }

    return answer;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        int rows = numRows;
        v.assign(rows,vector<int>());
        for (int i = 0; i < rows; i++)
        {
            int val = 1;
            for (int k = 0; k <= i; k++)
            {
                v[i].push_back(val);
                val = val * (i - k) / (k + 1);
            }
        }
        return v;
    }
};
class Solution {
    int dfs(string &floor, int Carpets, int Len, int idx, vector<vector<int>> &dp)
    {
        if(idx >= floor.size())
            return 0;
        int val = 0;
        if(dp[idx][Carpets] != -1) return dp[idx][Carpets];
        if(Carpets == 0)
        {
            for(int i = idx; i < floor.size(); i++)
                if(floor[i] == '1') val++;
        }
        else
        {
            if(floor[idx] == '0')
                val = dfs(floor, Carpets, Len, idx+1, dp);
            else
            {
                val = min(1+dfs(floor, Carpets, Len, idx+1, dp), dfs(floor, Carpets-1, Len, idx+Len, dp));
            }
        }
        return dp[idx][Carpets] = val;
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n+1, vector<int> (numCarpets+1, -1));
        return dfs(floor, numCarpets, carpetLen, 0, dp);
    }
};
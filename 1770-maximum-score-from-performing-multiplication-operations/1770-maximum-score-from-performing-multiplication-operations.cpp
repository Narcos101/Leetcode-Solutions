class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i = m-1; i >= 0;i--){
            for(int j = i; j >= 0;j--){
                dp[i][j] = max(nums[j] * mul[i] + dp[i+1][j+1], nums[n-1-(i-j)] * mul[i] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
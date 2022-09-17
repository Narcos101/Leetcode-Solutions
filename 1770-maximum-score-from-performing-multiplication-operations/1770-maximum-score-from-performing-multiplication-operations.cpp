class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        vector<int>dp(m+1,0);
        for(int i = m-1; i >= 0;i--){
            vector<int>newdp = dp;
            for(int j = i; j >= 0;j--){
                dp[j] = max(nums[j] * mul[i] + newdp[j+1], nums[n-1-(i-j)] * mul[i] + newdp[j]);
            }
        }
        return dp[0];
    }
};
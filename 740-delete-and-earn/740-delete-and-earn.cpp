class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(10002,0);
        vector<int>freq(10002,0);
        for(auto num:nums){
            freq[num]++;
        }
        dp[0] = 0;
        dp[1] = 1 * freq[1];
        for(int i = 2; i < 10002; i++){
            dp[i] = max(dp[i-1], dp[i-2] + i * freq[i]);
        }
        return dp[10001];
    }
};
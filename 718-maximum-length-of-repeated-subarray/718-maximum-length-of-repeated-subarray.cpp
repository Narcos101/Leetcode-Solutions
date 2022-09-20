class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // top down memeo 
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<int>pre(n+1,0);
        for(int i = 1; i <= n;i++){
            vector<int>dp(n+1,0);
            for(int j = 1; j <= m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[j] = 1 + pre[j-1];
                }
                else{
                    dp[j] = 0;
                }
                ans = max(ans,dp[j]);
            }
            pre = dp;
        }
        return ans;
    }
};
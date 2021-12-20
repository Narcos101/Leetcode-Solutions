class Solution {
public:
    int lengthOfLIS(vector<int>& nums1) {
        int n = nums1.size();
        vector<int>nums2 = nums1;
        sort(nums2.begin(),nums2.end());
        int dp[n+1][n+1];
        for(int  i = n-1; i > 0; i--){
            if(nums2[i] == nums2[i-1]){
                nums2[i] = INT_MAX;
            }
        }
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if((nums1[i-1] == nums2[j-1]) && (nums2[j-1] != INT_MAX)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
};
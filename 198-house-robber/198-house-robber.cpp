class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return calc(nums,nums.size()-1,dp);
    }
    
    int calc(vector<int>&nums,int n,vector<int>&dp){
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = max(nums[n] + calc(nums,n-2,dp), calc(nums,n-1,dp)); 
    }
};
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        return calc(nums,target,0,dp);
    }
    
    int calc(vector<int>&nums,int target,int n, vector<vector<int>>&dp){
        if(target < 0 || n >= nums.size()){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        return dp[n][target] = calc(nums,target-nums[n],0,dp) + calc(nums,target,n+1,dp);
        
    }
    
    
};
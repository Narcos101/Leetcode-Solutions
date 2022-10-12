class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // trying all the possible combinations 
        int n = arr.size();
        int ans = 0;
        vector<int>dp(n+1,-1);
        return calc(n,arr,k,0,dp);
    }
    
    int calc(int n,vector<int>&nums,int k,int index,vector<int>&dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int maxx = nums[index];
        int ans = maxx + calc(n,nums,k,index+1,dp);
        int cnt = 1;
        for(int i = 1; i <= k-1;i++){
            cnt++;
            if(index + i < n){
                maxx = max(maxx,nums[index+i]);
                int val = (cnt * maxx) + calc(n,nums,k,index+i+1,dp); 
                
                ans = max(ans,val);    
            }
            else{
                break;
            }
        }
        return dp[index] = ans;
    }
};
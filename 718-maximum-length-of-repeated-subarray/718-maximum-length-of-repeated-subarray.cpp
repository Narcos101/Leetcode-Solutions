class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // top down memeo 
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        calc(nums1,nums2,i,j,n,m,ans,dp);
        return ans;
    }
    
    int calc(vector<int>&nums1,vector<int>&nums2,int i,int j,int n,int m,int&ans,vector<vector<int>>&dp){
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int con1 = 0;
        int con2 = 0;
        int con3 = 0;
        if(nums1[i] == nums2[j]){
            con1 = 1 + calc(nums1,nums2,i+1,j+1,n,m,ans,dp);
            ans = max(ans,con1);
        }      
        calc(nums1,nums2,i+1,j,n,m,ans,dp);
        calc(nums1,nums2,i,j+1,n,m,ans,dp);
        dp[i][j] = max(con1,dp[i][j]);
        return dp[i][j];
    }    
};
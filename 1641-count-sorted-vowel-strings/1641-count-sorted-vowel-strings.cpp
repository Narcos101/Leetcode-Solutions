class Solution {
public:
    int countVowelStrings(int n) {
        // a e i o u 
        int index = 0;
        vector<vector<int>>dp(6,vector<int>(n+1,-1));
        vector<char>s{'a','e','i','o','u'};
        string ans = "";
        return calc(s,n,index,ans,dp);
    }
    
    int calc(vector<char>&s, int n, int index,string ans,vector<vector<int>>&dp){
        if(index >= s.size() || ans.size() > n){
            return 0;
        }
        if(ans.size() == n){
            return 1;
        }
        if(dp[index][ans.size()] != -1){
            return dp[index][ans.size()];
        }
        return dp[index][ans.size()] = calc(s,n,index,ans+s[index],dp) + calc(s,n,index+1,ans,dp);
    }
    
    
};
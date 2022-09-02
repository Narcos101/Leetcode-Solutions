class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return calc(word1,word2,i,j,n,m,dp);
    }
    
    int calc(string&word1,string&word2,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i == n && j == m){
            return 0;
        }
        if(i >= n){
            return m-j;
        }
        if(j >= m){
            return n-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            return dp[i][j] = calc(word1,word2,i+1,j+1,n,m,dp);
        }
        else{
            int cnt =  calc(word1,word2,i + 1,j,n,m,dp);
            int cnt1 = calc(word1,word2,i,j+1,n,m,dp);
            return dp[i][j] = 1 + min({cnt,cnt1});
        }
    }
};
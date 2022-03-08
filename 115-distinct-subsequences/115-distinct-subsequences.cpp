class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return calc(s,t,0,0,dp,0);           
    }
    int calc(string&s, string&t, int i, int j,vector<vector<int>>&dp,int cnt){
        if(j == t.size()){
            return 1;
        }
        if(i >= s.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = calc(s,t,i+1,j+1,dp,cnt+1) +  calc(s,t,i+1,j,dp,cnt);
        }
        else{
            return dp[i][j] = calc(s,t,i+1,j,dp,cnt);
        }
    }
};
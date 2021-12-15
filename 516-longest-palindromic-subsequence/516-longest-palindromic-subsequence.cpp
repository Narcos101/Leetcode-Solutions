class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int dp[s1.size()+1][s1.size()+1];
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        for(int i = 0;i <= s1.size(); i++){
            for(int j = 0;j <= s1.size(); j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
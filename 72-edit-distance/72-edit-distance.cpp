class Solution {
public:
    int minDistance(string word1, string word2){
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return calc(word1.size()-1,word2.size()-1,word1,word2,dp);
    }

    int calc(int i, int j, string&word1, string&word2,vector<vector<int>>&dp){
        if(i == -1){
            return j+1;    
        }
        if(j == -1){
            return i+1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            return dp[i][j] = calc(i-1,j-1,word1,word2,dp);
        }
        else{
            int add = calc(i,j-1,word1,word2,dp);
            int replace = calc(i-1,j-1,word1,word2,dp);
            int deleted = calc(i-1,j,word1,word2,dp);
            return dp[i][j] = 1 + min(add,min(replace,deleted));
        }
    }
};
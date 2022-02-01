class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size()));
        int count = 0;
        for(int i = 1; i < matrix.size(); i++){
            dp[i][0] = matrix[i][0]-'0';
            if(matrix[i][0] == '1'){
                count = 1;
            } 
        }
        for(int j = 0; j < matrix[0].size(); j++){
            dp[0][j] = matrix[0][j]-'0';
            if(matrix[0][j] == '1'){
                count = 1;
            } 
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1;j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
                count = max(count,dp[i][j]);
            }
        }    
        return count * count;    
    }
};

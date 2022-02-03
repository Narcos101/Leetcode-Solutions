class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
        int minn = INT_MAX;
        for(int i = 0; i < n;i++){
            minn = min(minn,calc(matrix,dp,0,i));
        }
        return minn;
    }
    
    int calc(vector<vector<int>>& matrix,vector<vector<int>>&dp,int i,int j){
        if(j < 0 || j > matrix.size()-1){
            return INT_MAX-100;
        }
        if(i >= matrix.size()){
            return 0;
        }
        
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }
        int ll = matrix[i][j] + calc(matrix,dp,i+1,j-1);
        int l = matrix[i][j] + calc(matrix,dp,i+1,j);
        int lr = matrix[i][j] + calc(matrix,dp,i+1,j+1);
        return dp[i][j] = min(ll,min(l,lr));
    }
};
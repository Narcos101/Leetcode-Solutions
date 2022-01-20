class Solution {
public:
    
    int mod = 1000000007;
    
    int knightDialer(int n) {
        
        vector<vector<int>> paths = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        int answer = 0;
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        for(int i = 0; i <= 9; i++){
            answer = (answer+ calc(paths,i,n,1,dp)) % mod;
        }
        return answer;
    }
    
    int calc(vector<vector<int>>&paths,int index,int n,int cnt,vector<vector<int>>&dp){
        if(cnt == n){
            return dp[cnt][index] = 1;
        }
        if(dp[cnt][index] != -1){
            return dp[cnt][index];
        }
        dp[cnt][index] = 0;
        for(int i = 0; i < paths[index].size(); i++){
            dp[cnt][index] = (dp[cnt][index]+ calc(paths,paths[index][i],n,cnt+1,dp)) % mod;
        }
        return dp[cnt][index];
    }
};
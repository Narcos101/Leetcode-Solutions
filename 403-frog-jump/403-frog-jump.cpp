class Solution {
public:
    bool canCross(vector<int>& stones) {
        int value = stones[1];
        if(stones[0] + 1 != stones[1]){
            return false;
        }
        int n = stones.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        unordered_map<int,int>mpp;
        for(int i = 0; i < stones.size();i++){
            mpp[stones[i]] = i;
        }
        // for storing the positions 
        
        return calc(stones,1,value,1,mpp,dp);
    }
    
    bool calc(vector<int>&stones,int index,int value,int k,unordered_map<int,int>&mpp,vector<vector<int>>&dp){
        if(index == stones.size()-1){
            return true;
        }
        if(dp[index][k] != -1){
            return dp[index][k];
        }
        bool jump1 = false;
        bool jump2 = false;
        bool jump3 = false;
        if(k-1 > 0 && mpp.find(value + k - 1) != mpp.end()){
            jump1 = calc(stones,mpp[value+k-1],value+k-1,k-1,mpp,dp);
        }
        if(mpp.find(value + k) != mpp.end()){
            jump2 = calc(stones,mpp[value+k],value+k,k,mpp,dp);
        }
        if(mpp.find(value + k + 1) != mpp.end()){
            jump3 = calc(stones,mpp[value + k + 1],value + k + 1,k+1,mpp,dp);
        }
        return dp[index][k] = jump1 || jump2 || jump3;
    }
    
    
    
};
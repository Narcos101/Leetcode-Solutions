class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        vector<int>dp;
        sort(env.begin(),env.end(),[&](vector<int>&a,vector<int>&b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; 
        });
        for(int i = 0; i < n;i++){
            int elm = env[i][1];
            int idx = lower_bound(dp.begin(),dp.end(),elm)-dp.begin();
            if(idx == dp.size()){
                dp.push_back(elm);
            }
            else{
                dp[idx] = elm;
            }
        }
        return dp.size();
    }
};
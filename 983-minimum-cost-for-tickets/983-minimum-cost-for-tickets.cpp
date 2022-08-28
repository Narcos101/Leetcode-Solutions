class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>>dp(n+1,vector<int>(396,-1));
        return calc(days,costs,dp,0,0);
    }
    
    int calc(vector<int>&days,vector<int>&costs,vector<vector<int>>&dp,int index,int day){
        if(index >= days.size()){
            return 0;
        }
        if(dp[index][day] != -1){
            return dp[index][day];
        }
        int con1 = INT_MAX;
        int con2 = INT_MAX;
        int con3 = INT_MAX;
        con1 = costs[0] + calc(days,costs,dp,index+1,days[index] + 0);
        con2 = costs[1] + calc(days,costs,dp,index+1,days[index] + 6);
        con3 = costs[2] + calc(days,costs,dp,index+1,days[index] + 29);
        
        int ans = INT_MAX;
        ans = min(con1,min(con2,con3));
        if(day >= days[index]){
            int val = calc(days,costs,dp,index+1,day);
            ans = min(ans,val);
        } 
        return dp[index][day] = ans;
    }
};
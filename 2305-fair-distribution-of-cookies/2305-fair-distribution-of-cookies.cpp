class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int index = 0;
        vector<int>v(k+1,0);
        int ans = INT_MAX;
        calc(cookies,k,index,ans,v,0);
        return ans; 
    }
    
    void calc(vector<int>&jobs,int k,int index,int &ans,vector<int>&v,int wt){
        if(wt >= ans){
            return;
        }
        if(index == jobs.size()){
            ans = min(ans,wt);
            return;
        }
        set<int>st;
        for(int i = 0; i < k;i++){
            if(st.find(jobs[index]) != st.end()) continue;
            if(v[i] + jobs[index] >= ans) continue;
            v[i] += jobs[index];
            st.insert(v[i]);
            calc(jobs,k,index+1,ans,v,max(wt,v[i]));
            v[i] -= jobs[index];
        }
    }
};
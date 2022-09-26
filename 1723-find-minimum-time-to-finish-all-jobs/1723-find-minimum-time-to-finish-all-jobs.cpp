class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int index = 0;
        vector<int>v(k+1,0);
        int ans = INT_MAX;
        calc(jobs,k,index,ans,v,0);
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
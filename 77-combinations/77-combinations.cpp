class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        for(int i = 1; i <= n; i++){
            v.push_back(i);
            dfs(ans,n,k,v,i+1);
            v.pop_back();
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>&ans, int n, int k, vector<int>&v, int index){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        if(index > n){
            return;
        }
        v.push_back(index);
        dfs(ans,n,k,v,index+1);
        v.pop_back();
        dfs(ans,n,k,v,index+1);
    }
    
};
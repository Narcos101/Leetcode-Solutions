class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        int index = 1;
        calc(k,n,v,ans,index,0);
        return ans;
    }
    
    void calc(int k, int n, vector<int>&v, vector<vector<int>>&ans, int index,int sum){
        if(index > 10){
            return;
        }
        if(sum == n && v.size() == k){
            ans.push_back(v);
            return;
        }
        v.push_back(index);
        calc(k,n,v,ans,index+1,sum+index);
        v.pop_back();
        calc(k,n,v,ans,index+1,sum);        
    }
    
};
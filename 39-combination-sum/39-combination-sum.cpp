class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n = c.size();
        vector<int>v;
        vector<vector<int>>ans;
        int sum = 0;
        calc(ans,v,c,target,0,sum);
        return ans;
    }
    
    void calc(vector<vector<int>>&ans, vector<int>&v,vector<int>&c,int& target,int index, int sum){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        if(index == c.size()){
            return;
        }

        
        if(sum + c[index] <= target){
            v.push_back(c[index]);
            calc(ans,v,c,target,index,sum+c[index]);
            v.pop_back();
        }
        calc(ans,v,c,target,index+1,sum);
    }
};
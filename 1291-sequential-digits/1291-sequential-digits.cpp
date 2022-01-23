class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i = 1; i <= 9; i++){
            calc(i,ans,low,high,i+1);    
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    
    void calc(int num, vector<int>&ans, int low, int high,int cnt){
        if(num > high || cnt > 10){
            return;
        }
        if(num >= low && num <= high){
            ans.push_back(num);
        }
        calc(num * 10 + cnt,ans,low,high,cnt+1);
    }
};
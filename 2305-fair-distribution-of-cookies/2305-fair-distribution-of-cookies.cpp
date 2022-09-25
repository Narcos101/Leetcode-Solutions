class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int i = 0;
        vector<int>v(k,0);
        int ans = INT_MAX;
        int maxx = INT_MIN;
        calc(n,cookies,v,i,k,maxx,ans);
        return ans;
    }
    
    
    void calc(int n,vector<int>&cookies,vector<int>&v,int i,int k,int maxx,int&ans){
        if(i == cookies.size()){
            ans = min(ans,maxx);
            return;
        }
        for(int j = 0; j < k;j++){
            v[j] += cookies[i];
            calc(n,cookies,v,i+1,k,max(maxx,v[j]),ans);
            v[j] -= cookies[i];
        }
    }

};
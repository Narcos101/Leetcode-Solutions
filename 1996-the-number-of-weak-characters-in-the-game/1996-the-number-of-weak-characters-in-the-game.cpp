class Solution {
public:
    
    
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[&](vector<int>&a,vector<int>&b){
            return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
        });
        int maxx = 0;
        int n = p.size();
        int cnt = 0;
        for(int i = n-1; i >= 0;i--){
            if(p[i][1] < maxx){
                cnt++;
            }
            maxx = max(maxx,p[i][1]);
        }
        return cnt;
    }
};
class Solution {
public:
    int minCost(string s, vector<int>& nt) {
        int n = s.size();
        int m = nt.size();
        // among all the consecutive baloons 
        // just remove the baloons that take the least time to finish 
        // no need to use a priority queue directly take two baloons and keep on comparing them 
        // till they're consecutive
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(i + 1 < n){
                if(s[i] == s[i+1]){
                    int maxx = nt[i];
                    int j = i;
                    while(j < n){
                        if(j+1 < n && s[j] == s[j+1]){
                            ans += min(maxx,nt[j+1]);
                            maxx = max(maxx,nt[j+1]);
                        }
                        else{
                            break;
                        }
                        j++;
                    }
                    i = j;
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};
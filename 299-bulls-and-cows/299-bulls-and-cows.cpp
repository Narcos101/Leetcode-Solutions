class Solution {
public:
    string getHint(string s, string g) {
        int n = s.size();
        map<int,int>mpp;
        map<char,int>mpp1;
        string ans = "";
        int bulls = 0;
        int cows = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == g[i]){
                mpp[i]++;
                bulls++;
            }
            else{
                mpp1[g[i]]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(mpp[i]){
                continue;
            }
            else{
                if(mpp1[s[i]]){
                    mpp1[s[i]]--;
                    cows++;
                }
            }
        }
        ans += to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
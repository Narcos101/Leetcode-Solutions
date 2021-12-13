class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        if(n == 1){
            return 1;
        }
        int cnt = 0;
        char previous = ' ';
        int maxx = INT_MIN;
        for(int i = 0;i < n; i++){
            char c = s[i];
            if(c == previous){
                cnt++;
            }
            else{
                cnt = 1;
                previous = c;
            }
            maxx = max(cnt,maxx);
        }
        return maxx;
    }
};
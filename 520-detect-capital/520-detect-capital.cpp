class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        int left = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(left == -1 && isupper(s[i])){
                left = i;
                cnt++;
            }
            else if(isupper(s[i])){
                cnt++;
            }
        }
        if((left == -1 && cnt == 0) || (left != -1 && cnt == s.size())|| (left == 0 && cnt == 1)){
            // cout << left << " " << cnt << endl; 
            return true;
        }
        return false;
    }
};
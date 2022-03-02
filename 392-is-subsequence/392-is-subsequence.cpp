class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(true){
            if(cnt == s.size()){
                return true;
            }
            if(j >= t.size()){
                cout << j << endl;
                break;
            }
            if(s[i] == t[j]){
                i++;
                cnt++;
            }
            j++;
        }
        return false;
    }
};
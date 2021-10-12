class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool alpha[26] = {};
        for(int i = 0; i < allowed.size(); i++){
            if(!alpha[allowed[i]-'a']){
                alpha[allowed[i]-'a'] = true;
            }
        }
        int cnt = 0;
        for(auto i: words){
            int flag = 0;
            for(auto &ch: i){
                if(!alpha[ch-'a']){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                cnt++;
            }
        }
        return cnt;
    }
};
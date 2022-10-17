class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.size();
        if(s.size() < 26){
            return false;
        }
        vector<int>v(26,0);
        for(auto ch : s){
            v[ch-'a']++;
        }
        for(int i = 0; i < 26;i++){
            if(v[i] == 0){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        int absent = 0;
        for(int i = 0; i < s.size(); i++){
            if(cnt){
                if(s[i] == 'L'){
                    cnt++;
                    if(cnt >= 3){
                        return false;
                    }
                    continue;
                }
                else{
                    cnt = 0;
                }
            }
            else if(s[i] == 'L'){
                cnt++;
            }
            
            if(s[i] == 'A'){
                absent++;
            }
        }
        if(absent >= 2){
            return false;
        }
        return true;
    }
};
class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        bool flag = true;
        if(n == 1){
            return "";
        }
        for(int i = 0; i < n/2;i++){
            if(s[i] == s[n-i-1]){
                if(s[i] > 'a'){
                    s[i] = 'a';
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            s[n-1] = 'b'; 
        }
        return s;
    }
};
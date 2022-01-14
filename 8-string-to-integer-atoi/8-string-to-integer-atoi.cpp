class Solution {
public:
    int myAtoi(string s) {
        int n = s.size()-1;
        int i = 0;
       while(s[i] == ' '){
            i++;
        }
        bool isNegative = false;
        if(s[i] == '-'){
            isNegative = true;
            i++;
        }
        else if(s[i] == '+'){
            isNegative = false;
            i++;
        }
        int result = 0;
        while(i <= n && isDigit(s[i])){
            int digit = s[i]-'0';
            if((result > INT_MAX/10) || (result == INT_MAX/10 && digit > 7)){
                return isNegative ? INT_MIN:INT_MAX;
            }
            result = result * 10 + digit;
            i++;
        }
        return isNegative ? -1 * result: result;
    }
    
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    
};
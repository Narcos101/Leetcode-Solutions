class Solution {
public:
    int secondHighest(string s) {
        int firstval = -1;
        int secondval = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int c = s[i]-'0';
                if(c > firstval){
                    secondval = firstval;
                    firstval = c;
                }
                else if(c < firstval && c > secondval){
                    secondval = c;
                }
            }
        }
        return secondval;
    }
};
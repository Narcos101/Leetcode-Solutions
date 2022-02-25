class Solution {
public:
    int compareVersion(string s1, string s2) {
        // basically construct the number until a dot
        int i = 0;
        int j = 0;
        int n = s1.size();
        int m = s2.size();
        bool flag = 0;
        int num1 = 0;
        int num2 = 0;
        int mod = INT_MAX-1;
        while(i < n && j < m){
            num1 = 0;
            num2 = 0;
            while(s1[i] != '.' && i < n){
                if(i > 0 && s1[i] == '0' && s1[i-1] == '.'){
                    s1[i] = '.';
                }
                else{
                    num1 = (num1 * 10) + (s1[i]-'0');
                }
                i++;
            }     
            while(s2[j] != '.' && j < m){
                if(j > 0 && s2[j] == '0' && s2[j-1] == '.'){
                    s2[j] = '.';
                }
                else{
                    num2 = (num2 * 10) + (s2[j]-'0');
                }
                j++;
            }
            i++;
            j++;
            if(num2 > num1){
                return -1;
            }
            if(num2 < num1){
                return 1;
            }
        }
        if(num2 > num1){
            return -1;
        }
        if(num2 < num1){
            return 1;
        }
        num1 = 0;
        num2 = 0;
        while(i < n){
            while(s1[i] != '.' && i < n){
                if(i > 0 && s1[i] == '0' && s1[i-1] == '.'){
                    s1[i] = '.';
                }
                else{
                    num1 = (num1 * 10) + (s1[i]-'0');
                }
                i++;
            }
            i++;
            if(num1 != 0){
                return 1;
            }
        }
        while(j < m){
            while(s2[j] != '.' && j < m){
                if(j > 0 && s2[j] == '0' && s2[j-1] == '.'){
                    s2[j] = '.';
                }
                else{
                    num2 = (num2 * 10) + (s2[j]-'0');
                }
                j++;
            }  
            j++;
            if(num2 != 0){
                return -1;
            }
        }
        return 0;
    }
};
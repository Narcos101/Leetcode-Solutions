class Solution {
public:
    string pushDominoes(string s ) {
        int n = s.size();
        string ans = "";
        int i = 0;
        int j = 0;
        while(j < n){
            if((s[i] == '.' || s[i] == 'L') && s[j] == 'L'){
                for(int k = i; k < j;k++){
                    s[k] = 'L';
                } 
                i = j;
            }
            else if(s[i] == 'R' && s[j] == 'L'){
                for(int k = 1; k < ((j-i+1)/2);k++){
                    s[i + k] = 'R';
                    s[j - k] =  'L';
                }
                i = j;
            }
            else if(s[i] == 'R' && (s[j] == 'R')){
                for(int k = i; k <= j;k++){
                    s[k] = 'R';
                }
                i = j;
            }
            else if(s[i] == 'L' && s[j] == 'R' || (s[i] == '.' && s[j] == 'R')){
                i = j;
            }
            j++;
        }
        cout << i << " " << j << endl;
        if(s[i] == 'R' && s[j-1] == '.'){
            for(int k = i; k <= j-1;k++){
                s[k] = 'R';
            }
        }
        return s;
    }
};
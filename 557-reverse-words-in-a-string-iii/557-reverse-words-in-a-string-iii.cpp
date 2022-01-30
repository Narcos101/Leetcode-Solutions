class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(j,i-1,s);
                j = i+1;
            }
        }
        reverse(j,s.size()-1,s);
        return s;
    }
    
    void reverse(int start,int end,string&s){
        while(start <= end){
            swap(s[start++],s[end--]);
        }
    }
    
};
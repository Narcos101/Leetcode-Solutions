class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            res += isPalindrome(i,i,s);
            res += isPalindrome(i,i+1,s);
        }
        return res;
    }
    
    int isPalindrome(int start, int end, string s){
        int count = 0;
        while(start >= 0 && end < s.size() && s[start--] == s[end++]){
            count++;
        }
        return count;
    }
    
    
    
};
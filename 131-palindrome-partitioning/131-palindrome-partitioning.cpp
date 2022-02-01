class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        calc(ans,v,0,s);
        return ans;
    }
    
    void calc(vector<vector<string>>&ans,vector<string>&v,int index,string&s){
        if(index == s.size()){
            ans.push_back(v);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(index,i,s)){
                v.push_back(s.substr(index,i-index+1));
                calc(ans,v,i+1,s);
                v.pop_back();
            }
        }
    }
    
    
    
    
     bool isPalindrome(int start, int end, string &s){
         while(start <= end){
             if(s[start++] != s[end--]){
                 return false;
             }
         }
         return true;
     }
    
};
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string>ans;
        string news;
        calc(s,n,ans,news,0);
        return ans;
    }
    
    void calc(string s, int n,vector<string>&ans,string news,int index){
        
        if(index == n){
            ans.push_back(s);
            return;
        }
        
        
        if(isalpha(s[index])){
            if(isupper(s[index])){
                s[index] = s[index] - 'A' + 'a';
                calc(s,n,ans,news,index+1);
                s[index] = s[index] + 'A' - 'a';
            }
            else if(islower(s[index])){
                s[index] = s[index] - 'a' + 'A';
                calc(s,n,ans,news,index+1);
                s[index] = s[index] + 'a' - 'A';
            }
            calc(s,n,ans,news,index+1);
        }
        else{
            calc(s,n,ans,news,index+1);
        }
        
    }
    
};
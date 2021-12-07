class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<int> stc;
        unordered_map<int,bool> visited;
        int lastIdx[26] ;
        string ans = "";
        for(int i=1 ; i<=26;i++)
            visited[i] = false;
        
        for(int i=0 ; i<s.size();i++)
            lastIdx[s[i] - 'a'] = i;
        
        for(int i=0 ; i<s.size();i++){
             int val = s[i] - 'a';
            if(visited[val]) continue;
            while(!stc.empty()  && stc.top() > val && lastIdx[stc.top()] > i){
                visited[stc.top()] = false;
                 stc.pop();
            }
            stc.push(val);
            visited[val] = true;
        }
        while(!stc.empty()){
            ans+= stc.top() + 'a';
            stc.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
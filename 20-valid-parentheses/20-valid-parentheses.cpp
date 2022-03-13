class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int>st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    st.push(s[i]);
                }
                else{
                    if(s[i] == ')' && st.top() == '(' || (s[i] == ']' && st.top() == '[' || (st.top() == '{' && s[i] == '}'))){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
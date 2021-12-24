class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = 0; i < n; i++){
            int num = temp[i];
            while(st.size() && temp[st.top()] < num){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
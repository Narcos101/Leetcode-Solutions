class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int>st;
        map<int,int>mpp;
        for(int num:nums){
            while(st.size() && st.top() < num){
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int>ans;
        for(auto i: findNums){
            ans.push_back(mpp.count(i) ? mpp[i] : -1); 
        } 
        return ans;
    }
};
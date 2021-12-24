class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n,-1);
        for(int i = 0; i < 2*n;i++){
            int num = nums[i % n];
            while(st.size() && nums[st.top()] < num){
                ans[st.top()] = num;
                st.pop();
            }
            st.push(i%n);
        }
        return ans;
    }
};
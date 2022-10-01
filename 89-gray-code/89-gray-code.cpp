class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        // n for looping for going through the number of digits each and every time
        ans.push_back(0);
        for(int i = 0; i < n;i++){
            int size = ans.size();
            for(int k = size-1; k >= 0;k--){
                ans.push_back(ans[k] | 1 << i);
            }
        }
        return ans;
    }
};
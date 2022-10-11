class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int st = nums[0];
        for(int i = 1; i < n;i++){
            if(!(nums[i] > st)){
                int newval = (st-nums[i]) + 1;
                ans += newval;
                st = nums[i] + newval;
            }
            else{
                st = nums[i];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = nums[0];
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == majority){
                ans++;
            }
            else if(nums[i] != majority){
                ans--;
                if(ans == 0){
                    majority = nums[i];
                    ans = 1;
                }
            }
        }
        return majority;
    }
};
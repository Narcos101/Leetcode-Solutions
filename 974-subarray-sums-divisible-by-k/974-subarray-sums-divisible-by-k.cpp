class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        unordered_map<int,int>mpp; 
        mpp[0] = 1;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            int mod = ((sum % k) + k) % k;
            ans += mpp[mod];
            mpp[mod]++;
        }
        return ans;
    }
};
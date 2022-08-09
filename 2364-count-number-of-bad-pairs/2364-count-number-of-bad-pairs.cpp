class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        // 4 1 3 3 
        // 1 2 3 4 5
        unordered_map<int,int>mpp;
        for(int i = n-1; i >= 0;i--){
            int diff = i-nums[i];
            ans += (n-i-1)-mpp[diff];
            cout << ans << endl;
            mpp[diff]++;
        }
        return ans;
    }
    
};
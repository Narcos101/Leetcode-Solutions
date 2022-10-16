class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        bool mini = false;
        bool maxi = false;
        int j = 0;
        int minStart = -1;
        int maxStart = -1;
        for(int i = 0; i < n;i++){
            int num = nums[i];
            if(minK > nums[i] || maxK < nums[i]){
                mini = false;
                maxi = false;
                minStart = -1;
                maxStart = -1;
                j = i + 1;
                continue;
            }
            if(num == minK){
                mini = true;
                minStart = i;
            }
            if(num == maxK){
                maxi = true;
                maxStart = i;
            }
            if(mini && maxi){
                ans += (min(maxStart,minStart)-j+1);    
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 1;
        for(int i = n-1; i >= 0; i--){
            if(cnt == k){
                return nums[i];
            }
            else{
                cnt++;
            }
        }
        return -1;
    }
};
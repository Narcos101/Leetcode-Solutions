class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int maxx = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }                
            else if(nums[i-1] + 1 == nums[i]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            
            if(maxx < cnt){
                maxx = cnt;
            }
        }
        return maxx;
    }
};
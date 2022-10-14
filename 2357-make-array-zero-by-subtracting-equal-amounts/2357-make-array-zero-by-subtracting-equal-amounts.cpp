class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        
        for(int i = 0; i < n;i++){
            if(i == 0){
                if(nums[i] != 0){
                    ans++;
                }
            }
            else if(i-1 >= 0 && nums[i] != 0 && nums[i] != nums[i-1]){
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX/2;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int lo = i+1;
            int high = nums.size()-1;
            int value = nums[lo] + nums[high] + nums[i];
            while(lo < high){
                if(abs(value-target) < abs(ans-target)){
                    ans = value;
                }
                else if(value > target){
                    high = high-1;
                    value = value + nums[high] - nums[high+1]; 
                }
                else if(value < target){
                    lo = lo+1;  
                    value = value + nums[lo] - nums[lo-1];
                }
                else if(value == target){
                    return target;
                }
            }
        }
        return ans;
    }
};
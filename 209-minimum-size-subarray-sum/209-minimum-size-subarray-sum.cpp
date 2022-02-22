class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minLength = INT_MAX;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum >= target){
                while(sum >= target){
                    minLength = min(minLength,i-j+1);
                    sum -= nums[j];
                    j++;
                }
            }
        }  
        return minLength==INT_MAX?0:minLength;
    }
};
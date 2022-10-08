class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        int ans1 = INT_MAX;
        for(int i = 0;i < n;i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            else{
                int j = i+1;
                int k = n-1;
                int sum = nums[i];
                while(j < k){
                    int val = sum + nums[j] + nums[k];
                    if(ans > abs(target-val)){
                        ans = abs(target-val);
                        ans1 = val;
                    }
                    if(val == target){
                        return target;
                    }
                    else if(val > target){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        return ans1;
    }
};
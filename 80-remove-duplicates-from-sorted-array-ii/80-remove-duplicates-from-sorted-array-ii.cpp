class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int temp = 1;
        int cnt = 2;
        for(int i = 2; i < n; i++){
            if(((nums[i] == nums[temp]) && (nums[temp] != nums[temp-1])) || (nums[i] != nums[temp])){
                temp++;
                swap(nums[i],nums[temp]);
                cnt++;
            }    
        }
        return cnt;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        int correctpos;
        for(int i = 0;i < n;){
            if(nums[i] != i+1){
                correctpos = nums[i]-1;
                if(nums[i] != nums[correctpos]){
                    temp = nums[i];
                    nums[i] = nums[correctpos];
                    nums[correctpos] = temp;
                }
                else{
                    return nums[i];
                }
            }
            else{
                i++;
            }
        }
        return -1;
    }
};
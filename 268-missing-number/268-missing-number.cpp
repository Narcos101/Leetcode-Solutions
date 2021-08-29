class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int currentpos = 0;
        int temp = 0;
        // 9 6 4 2 3 5 7 0 1
        for(int i = 0; i < n;){
            currentpos = nums[i];
            if(currentpos < n && nums[i] != nums[currentpos]){
                temp = nums[i];
                nums[i] = nums[currentpos];
                nums[currentpos] = temp;
            }
            else{
                i++;
            }
        }
        for(int i= 0; i < n;i++){
            if(nums[i] != i){
                return i;
            }
        }
        return n;
    }
};
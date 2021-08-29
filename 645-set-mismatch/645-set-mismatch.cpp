class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        int correctpos;
        vector<int>v;
        for(int i = 0;i < n;){
            correctpos = nums[i]-1;
            if(nums[i] != nums[correctpos]){
                temp = nums[i];
                nums[i] = nums[correctpos];
                nums[correctpos] = temp;
            }
            else{
                i++;
            }
        }
        for(int i = 0; i < n;i++){
            if(nums[i] != i+1){
                v.push_back(nums[i]);
                v.push_back(i+1);
            }
        }
        return v;
    }
};        

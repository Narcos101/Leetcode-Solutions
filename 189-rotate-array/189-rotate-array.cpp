class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k >= nums.size()){
            k = k % nums.size();
        }
        reverse(0,nums.size()-1,nums);
        reverse(0,k-1,nums);
        reverse(k, nums.size()-1,nums);
    }
    
    
    void reverse(int start, int end, vector<int>&nums){
        while(start <= end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
};
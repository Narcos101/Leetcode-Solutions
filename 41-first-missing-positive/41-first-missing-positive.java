class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        
        for (int i = 0; i < n; ) {
            int idx = nums[i] - 1;
            // -1 != 
            if (idx >= 0 && idx < n && nums[idx] != nums[i]) {
                swap(nums, i, idx);
            } else {
                ++i;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
    
    private void swap(int[] nums, int l, int r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
}
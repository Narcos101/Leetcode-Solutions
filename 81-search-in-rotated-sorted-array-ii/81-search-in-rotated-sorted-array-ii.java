class Solution {
    public boolean search(int[] nums, int target) {
        if(nums == null || nums.length == 0) return false;
        
        int left = 0, right = nums.length - 1;
        while(left <= right && nums[left] == nums[right]) {
            if(nums[left] == target) {
                return true;
            }
            left++;
            right--;
        }
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return true;
            }
            
            if(nums[mid] >= nums[left]) {
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if(target <= nums[right] && target > nums[mid]) {
                    
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
}
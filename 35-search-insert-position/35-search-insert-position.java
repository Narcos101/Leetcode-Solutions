class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int mid = 0;
        int end = nums.length-1;
        if(target < nums[0]){
            return 0;
        }
        else if(target > nums[end]){
            return end+1;
        }
        else{
            while(start <= end){
                mid = (start + (end-start)/2);
                if(nums[mid] == target){
                    return mid;
                }
                else if(nums[mid] > target){
                    end = mid-1;
                }
                else if(nums[mid] < target){
                    start = mid+1;
                }   
            }    
        }
        if(nums[mid] > target){
            return mid;
        }
        else{
            return mid+1;
        }
    }
}
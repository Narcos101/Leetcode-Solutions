class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        k = n-k;
        int lo = 0;
        int hi = nums.length-1;
        while(lo < hi){
            int j = findPivot(nums,lo,hi);
            if(j < k){
                lo = j+1;
            }
            else if(j > k){
                hi = j-1;
            }
            else{
                break;
            }
        }
        return nums[k];
    }
    
    private int findPivot(int[] nums,int lo, int hi){
        int i = lo;
        int pivot = nums[hi];
        for(int j = lo; j < hi; j++){
            if(nums[j] <= pivot){
                swap(nums,i,j);
                i++;
            }
        }
        swap(nums,i,hi);
        return i;
    }
    
    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
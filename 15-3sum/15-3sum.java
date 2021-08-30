class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // O(n^3) solution would be keep two pointers and iterate through the array and record          their sum if it is equal to zero record it
        // O(n ^ 2)- iterate through the given array
        Arrays.sort(nums);
        List<List<Integer>>v = new LinkedList<>();
        for(int i = 0; i < nums.length-2; i++){
            if(i == 0 || i > 0 && nums[i] != nums[i-1]){
                int l = i+1;
                int h = nums.length-1;
                int sum = 0 - nums[i];
                while(l < h){
                    if(nums[l] + nums[h] == sum){
                        v.add(Arrays.asList(nums[l],nums[h],nums[i]));
                        while(l < h && nums[l] == nums[l+1]) l++;
                        while(l < h && nums[h] == nums[h-1]) h--;
                        l++;
                        h--;
                    }
                    else if(nums[l] + nums[h] > sum){
                        h--; 
                    }
                    else if(nums[l] + nums[h] < sum){
                        l++;
                    }
                }
            }   
        }
        return v;
        
    }
}
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums == null || nums.length == 0){
            return res;
        }
        
        int n = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n;j++){
                int target2 = target - nums[i] - nums[j];
                int front = j+1;
                int back = nums.length-1;
                while(front < back){
                    int value = nums[front]+nums[back];
                    if(value > target2){
                        back--;
                    }
                    else if(value < target2){
                        front++;
                    }
                    else{
                        List<Integer>quad = new ArrayList();
                        quad.add(nums[front]);
                        quad.add(nums[back]);
                        quad.add(nums[i]);
                        quad.add(nums[j]);
                        res.add(quad);
                        
                        
                        while(front < back && nums[front] == nums[front+1])front++;
                        while(front < back && nums[back] == nums[back-1])back--;
                        
                        front++;
                        back--;
                    }
                    
                }
                while(j + 1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i+1]) i++; 
        }
        return res;
    }
}
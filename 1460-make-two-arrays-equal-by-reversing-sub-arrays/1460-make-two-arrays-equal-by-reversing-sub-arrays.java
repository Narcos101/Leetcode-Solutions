class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] target1 = new int[1001];
        int n = arr.length;
        for(int i = 0; i < n; i++){
            target1[target[i]]++;
            target1[arr[i]]--;
        }
        
        for(int i = 0; i < target1.length;i++){
            if(target1[i] != 0) return false;
        }
        return true;
    }
}
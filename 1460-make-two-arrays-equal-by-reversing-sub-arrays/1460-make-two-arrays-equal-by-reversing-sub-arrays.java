class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] temp = new int[1001];
        for (int i = 0; i < target.length; i++) {
            temp[target[i]]++;
            temp[arr[i]]--;
        }
        for (int i = 0; i < temp.length; i++) {
            if (temp[i] != 0) return false;
        }
        return true; 
    }
}
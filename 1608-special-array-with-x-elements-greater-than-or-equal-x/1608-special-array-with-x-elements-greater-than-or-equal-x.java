class Solution {
    
    public int binary_search(int n, int[] arr){
        int size = arr.length;
        int start = 0;
        int end = arr.length-1;
        int ans = -1;
        while(start <= end){
            int mid = (start + (end-start)/2);
            if(arr[mid] >= n){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
   
    public int specialArray(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        for(int i = 0; i <= n;i++){
            int idx = binary_search(i,arr); 
            if(i == (n-idx)){
                return i;
            }
        }        
        return -1;     
    }
}
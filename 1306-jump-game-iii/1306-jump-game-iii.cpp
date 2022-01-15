class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size() || arr[start]<0){
            return false;
        }
        if(arr[start]==0) return true;
        
        arr[start]= -arr[start];
        
        bool ans1 =  canReach(arr,start+arr[start]);
        bool ans2 =  canReach(arr,start-arr[start]);
        
        arr[start]= -arr[start];// change data back to orginal 
        
        return ans1 || ans2;
        
        
    }
};
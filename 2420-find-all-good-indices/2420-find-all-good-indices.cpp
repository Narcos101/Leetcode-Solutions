class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        // 2 1 1 1 3 4 1
        
        // Sliding window 
        // for loop run hoga
        int n = nums.size();
        vector<int>dec(n+1,0);
        vector<int>asc(n+1,0);
        vector<int>ans;
        for(int i = 0; i < n;i++){
            if(i == 0 || nums[i] > nums[i-1]){
                dec[i] = 1;
            }  
            else{
                dec[i] = dec[i-1] + 1;
            }
        }
        for(int i = n-1; i >= 0;i--){
            if(i == n-1 || nums[i] > nums[i+1]){
                asc[i] = 1;
            }  
            else{
                asc[i] = asc[i+1] + 1;
            }
        } 
        for(int i = k; i < n-k;i++){
            if(i - 1 >= 0 && i + 1 < n){
                if(dec[i-1] >= k && asc[i+1] >= k){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
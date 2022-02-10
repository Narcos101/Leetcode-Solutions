class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // for two pointer method i need the array to be sorted 
        // another method would be to consider all the continuous subarrays and then find out the sum which is equal to k
        unordered_map<int,int>mpp;
        int sum = 0;
        int cnt = 0;
        
        // 0
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                cnt++;
            }
            if(mpp[sum-k]){
                cnt += mpp[sum-k];
            }
            mpp[sum]++;
            
        }
        return cnt;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;
        int sum = 0;
        unordered_map<int,int>mpp;
        mpp[0] = -1;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            int mod = sum % k;
            if(mpp.find(mod) == mpp.end()){
                mpp[mod] = i;
            }
            else if(i-mpp[mod]+1 > 2){
                return true;
            }
        }
        return false;
    }
};
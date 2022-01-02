class Solution {
public:
    int numPairsDivisibleBy60(vector<int>&nums){
        // brute force solution would be to consider each pair and then sum them up and modulo them by 60
        // and count the pairs solution O(n^2)
        
        map<int,int>mpp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = 60;
            int cnt = 1;
            while(nums[i] > num){
                num = 60 * cnt;
                cnt++;
            }
            if(mpp[num-nums[i]]){
                ans += mpp[num-nums[i]];
            }
            mpp[nums[i] % 60]++;
            
        }
        return ans;
    }
};
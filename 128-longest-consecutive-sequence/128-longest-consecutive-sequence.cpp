class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        map<int,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;        
        }
        int maxx = 1;
        int cnt = 1;
        for(auto i: mpp){
            if(mpp[i.first-1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            
            if(maxx < cnt){
                maxx = cnt;
            }
        }
        return maxx;
    }
};
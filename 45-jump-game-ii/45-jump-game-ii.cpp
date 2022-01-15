class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currend = 0;
        int currfar = 0;
        int cnt = 0;
        for(int i = 0;i < n-1; i++){
            currfar = max(currfar,nums[i]+i);
            if(i == currend){
                cnt++;
                currend = currfar;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxxindex = 0;
        for(int i = 0; i < n-1; i++){
            if(i <= maxxindex){
                int cnt = nums[i] + i;
                maxxindex = max(maxxindex,cnt);
            }
            else{
                break;
            }
        }
        if(maxxindex >= nums.size()-1){
            return true;
        }
        else{
            return false;
        }
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // 3 4 1 1 5
        // 
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num <= c1){
                c1 = num;
            }
            else if(num <= c2){
                c2 = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
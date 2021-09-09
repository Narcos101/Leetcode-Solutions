class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int maxi = 0;
        for(auto i:nums){
            if(i == 0){
                curr = 0;
            }
            else{
                curr++;
                maxi = max(maxi,curr);
                
            }
        }    
        return maxi;
    }
};
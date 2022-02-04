class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mpp;
        int maxx = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] == 0 ? -1:1);
            if(sum == 0){
                maxx = max(maxx,i+1);
            }
            else if(mpp.find(sum) != mpp.end()){
                maxx = max(maxx,i-mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
            
        }
        return maxx;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int cnt = 0;
        int maxx = 0;
        int ik = k;
        for(int i = 0; i < n;i++){
            if(nums[i] != 1){
                if(ik == 0){
                    start = i+1;
                }
                else{
                    if(k > 0){
                        k--;
                    }
                    else{
                        while(start <= i){
                            if(nums[start] == 0){
                                start++;
                                break;
                            }
                            start++;
                        }
                    }
                }
            }
            maxx = max(i-start+1,maxx);
        }
        return maxx;
    }
};
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // 1 1 3 4 5 
        // nlogn sort and then avoid duplicates and use a hashmap to mark the occurences -> n with two hashmaps
        
        // 1 2 3 4 5
               
        
        // 1 1 3 4 5 
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        int x = nums[0];
        int cnt = 0;
        int i = 0;
        if(nums[i]+k == nums[i]){
                if(mpp[nums[i]] > 1){
                    cnt = cnt + 1;
                }
        }
        else{
            if(mpp[nums[i] + k]){
                cnt++;
            }
        }
        for(int i = 1; i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                if(nums[i]+k == nums[i]){
                    if(mpp[nums[i]] > 1){
                        cnt = cnt + 1;
                    }
                }
                else{
                    if(mpp[nums[i] + k]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
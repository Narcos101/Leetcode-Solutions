class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        unordered_map<int,int>vacancy;
        for(int i = 0; i < nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i = 0; i < nums.size();i++){
            if(!freq[nums[i]]){
                continue;
            }
            if(vacancy[nums[i]]){
                freq[nums[i]]--;
                vacancy[nums[i]]--;
                vacancy[nums[i]+1]++;
            }
            else{
                int len = 0;
                int val = nums[i];
                for(int i = 0; i < 3; i++){
                    if(freq[val + i] != 0){
                        freq[val+i]--;
                    }
                    else{
                        break;
                    }
                    len++;
                    if(len == 3){
                        vacancy[val + len]++;
                        break;
                    }
                }
                if(len < 3){
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v = nums;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        map<int,int>mp;
        int rank = 0;
        for(int i = 0;  i < n; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = rank++;
            }
            else{
                rank++;
                continue;
            }
        }
        
        for(int i = 0; i < n; i++){
            v[i] = mp[v[i]];
        }
        return v;
    }
};
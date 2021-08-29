class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(mp[a] != mp[b]){
                return mp[a] < mp[b];
            }
            else{
                return b < a ;
            }
        });
        return nums;
    }
};
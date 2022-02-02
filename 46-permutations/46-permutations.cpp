class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        calc(ans,nums,0);
        return ans;
    }
    
    void calc(vector<vector<int>>&ans,vector<int>&nums,int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[index],nums[i]);
            calc(ans,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        // basically use a set to avoid all duplicate elements
        set<vector<int>>st;
        calc(nums,0,st);
        for(auto i: st){
            ans.push_back(i);
        }
        return ans;
    }
    
    void calc(vector<int>&nums,int index,set<vector<int>>&st){
        if(index == nums.size()){
            if(st.find(nums) == st.end()){
                st.insert(nums);
            }
            return;
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[index],nums[i]);
            calc(nums,index+1,st);
            swap(nums[index],nums[i]);
        }
    }
};
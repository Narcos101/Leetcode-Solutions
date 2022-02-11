class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp;
        for(int i = 0; i < nums1.size(); i++){
            mpp[nums1[i]]++;
        }
        vector<int>ans;
        for(int i = 0; i < nums2.size(); i++){
            if(mpp[nums2[i]]){
                ans.push_back(nums2[i]);
                mpp[nums2[i]] = 0;
            }
        }
        return ans;
    }
};
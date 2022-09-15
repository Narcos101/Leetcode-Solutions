class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int>ans;
        int n = c.size();
        unordered_map<int,int>mpp;
        sort(c.begin(),c.end());
        for(int i =0; i < c.size();i++){
            mpp[c[i]]++;
        }
        for(int i = 0; i < n;i++){
            int val = c[i];
            if(mpp[val] != 0){
                mpp[val]--;
                if(mpp[val * 2] != 0){
                    ans.push_back(val);
                    mpp[val * 2]--;
                    
                }
                else{
                    return {};
                }
            }
        }
        return ans;
    }
};
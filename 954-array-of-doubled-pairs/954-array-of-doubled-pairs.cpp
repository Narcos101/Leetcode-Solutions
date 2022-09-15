class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i < n;i++){
            mpp[arr[i]]++;
        }
        sort(arr.begin(),arr.end(),[&](int a,int b){
            return abs(a) < abs(b);
        });
        for(int i = 0; i < n;i++){
            int val = arr[i];
            if(mpp[val]){
                mpp[val]--;
                if(mpp[val * 2] != 0){
                    mpp[val * 2]--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
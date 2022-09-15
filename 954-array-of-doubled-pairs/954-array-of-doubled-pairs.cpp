class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i < n;i++){
            mpp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        for(int i = 0; i < n;i++){
            int val = arr[i];
            if(val < 0){
                if(mpp[val] != 0){
                    mpp[val]--;
                    if(val % 2){
                        return false;
                    }
                    if(mpp[val/2] != 0){
                        mpp[val/2]--;
                    }
                    else{
                        return false;
                    }
                } 
            }
            else{
                if(mpp[val] != 0){
                    mpp[val]--;
                    if(mpp[val * 2] != 0){
                        mpp[val * 2]--;
                    }
                    else{
                        return false;
                    }
                }    
            }
            
        }
        return true;
    }
};
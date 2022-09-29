class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // simply a heap 
        sort(arr.begin(),arr.end(),[&](int a,int b){
            return abs(a-x) == abs(b-x) ? a < b : abs(a-x) < abs(b-x);
        });
        vector<int>ans;
        for(int i = 0; i < k;i++){
            ans.push_back(arr[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
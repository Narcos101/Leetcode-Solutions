class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        int n = arr2.size();
        for(int i = 0; i < n;i++){
            mp[arr2[i]] = i;
        }
        sort(arr1.begin(),arr1.end(),[&](int a,int b){
            if(mp.find(a) != mp.end() && mp.find(b) != mp.end()){
                return mp[a] < mp[b];
            }
            else if(mp.find(a) == mp.end() && mp.find(b) == mp.end()){
                return a < b;
            }
            else if(mp.find(a) != mp.end()){
                return true;
            }
            return false;
        });
        mp.clear();
        return arr1;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mpp;
        multiset<int>st;
        for(int i = 0; i < arr.size();i++){
            mpp[arr[i]]++;
        }
        int ans = mpp.size();
        for(auto i: mpp){
            st.insert(i.second);
        }
        for(auto s: st){
            if(k >= s){
                k-=s;
                ans--;
            }   
            if(k == 0){
                break;
            }
        }
        return ans;
    }
};
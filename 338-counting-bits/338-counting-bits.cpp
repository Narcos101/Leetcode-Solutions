class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>arr;
        int i = 0;
        while(i <= n){
            arr.push_back(__builtin_popcount(i));
            i++;
        }
        return arr;
    }
};
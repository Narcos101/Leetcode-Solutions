class Solution {
public:
    long mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        long size = 0;
        long ans = 0;
        for(int i = 1;i <= n;i++){
            int nd = log2(i) + 1;
            ans = ((ans << nd) % mod + i) % mod;
        }
        return ans;
    }
}; 
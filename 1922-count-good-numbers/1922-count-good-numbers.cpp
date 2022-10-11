#define ll long long


class Solution {
public:
    int mod = 1e9 + 7;
    
    ll power(ll y,ll x){
        int res = 1;
        while(y > 0){
            if(y & 1) res = (res * x) % mod;
            y >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }
    
    
    int countGoodNumbers(long long n) {
        ll fours = n / 2;
        ll fives = n - n/2;
        return (power(fours,4) % mod * power(fives,5))%mod;
    }
};
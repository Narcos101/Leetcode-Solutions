class Solution {
public:
    int integerBreak(int n) {
        int product = 0;
        unordered_map<int,int>mpp;
        for(int i = 1; i < n; i++){
            product = max(product,i * breakFunc(n-i,mpp));    
        }
        return product;
    }
    
    int breakFunc(int n,unordered_map<int,int>&mpp){
        if(n == 0){
            return 1;
        }
        if(mpp.find(n) != mpp.end()){
            return mpp[n];
        }
        int product = 0;
        for(int i = 1; i <= n; i++){
            product = max(product,i * breakFunc(n-i,mpp));
        }
        return mpp[n] = product;
    }
    
};
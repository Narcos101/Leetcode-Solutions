class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>v;
        if(n == 1){
            return true;  
        }
        if((n & n-1) == 0){
            return true;
        }
        while(n != 0){
            int rem = n % 10;
            v.push_back(rem);
            n /= 10;
        }
        sort(v.begin(),v.end());
        do{
            int newint = 0;
            for(int i = 0;i < v.size();i++){
                newint = newint * 10 + v[i];
            }
            if(v[0] == 0){
                continue;
            }
            else{
                if((newint & (newint-1)) == 0){
                    return true;
                }
            }
        }while(next_permutation(v.begin(),v.end()));
        
        return false;
    }
};
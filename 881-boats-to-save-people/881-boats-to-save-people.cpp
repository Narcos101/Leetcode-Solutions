class Solution {
public:
    int numRescueBoats(vector<int>& b, int l) { 
        sort(b.begin(),b.end());
        int n = b.size()-1;
        int i = 0;
        int j = n;
        int ans = 0;
        while(i <= j){
            if(i == j){
                return ans+1;
            }
            if(b[i] + b[j] <= l){
                i++;
                j--;
            }
            else{
                j--;
            }
            ans++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int digit = 0;
        for(int i = 1;i <= 9;i++){
            digit = i;
            for(int j = i+1; j <= 9;j++){
                 digit = (digit * 10) + j;
                if(digit >= low && digit <= high){
                    ans.push_back(digit);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
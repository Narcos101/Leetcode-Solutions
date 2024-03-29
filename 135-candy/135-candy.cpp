class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>ans(n,1);
        int ans1 = 0;
        for(int i = 1; i < n;i++){
            if(ratings[i] > ratings[i-1]){
                if(ans[i] <= ans[i-1]){
                    ans[i] = ans[i-1] + 1;
                }
            }
        }
        for(int i = n-2; i >= 0;i--){
            if(ratings[i] > ratings[i+1]){
                if(ans[i] <= ans[i+1]){
                    ans[i] = ans[i+1] + 1;
                }
            }
        }
        for(int i = 0; i <ans.size();i++){
            ans1 += ans[i];
        }
        return ans1;
    }
};
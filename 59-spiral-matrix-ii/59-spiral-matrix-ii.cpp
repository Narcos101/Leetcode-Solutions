class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int cnt = 1;
        while(cnt <= (n * n)){
            for(int i = left; i <= right; i++){
                ans[up][i] = cnt++;                
            }
            for(int i = up+1; i <= down;i++){
                ans[i][right] = cnt++;
            }
            if(up != down){
                for(int i = right-1; i >= left; i--){
                    ans[down][i] = cnt++;
                }           
            }
            if(left != right){
                for(int i = down-1; i > up; i--){
                    ans[i][left] = cnt++;
                }
            }
            up++;
            down--;
            left++;
            right--;
        }
        return ans;
    }
};
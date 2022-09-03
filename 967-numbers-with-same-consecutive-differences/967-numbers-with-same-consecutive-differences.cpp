class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        queue<int>q;
        int cnt = 1;
        for(int i = 1; i<= 9; i++){
            q.push(i);
        }
        unordered_map<int,int>mpp;
        while(!q.empty()){
            int sn = q.size();
            for(int i = 0; i < sn;i++){
                int top = q.front();
                int rem = top % 10;
                if(cnt == n){
                    if(mpp[top] == 0){
                        ans.push_back(top);
                        mpp[top]++;
                    }
                }
                else{
                    if(rem + k <= 9){
                        q.push(top*10 + (rem + k));
                    }
                    if(rem - k >= 0){
                        q.push(top*10 + (rem -k));
                    }
                }
                q.pop();     
            }
            cnt++;
        }
        return ans;
    }
};
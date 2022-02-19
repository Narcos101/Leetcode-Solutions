class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int ans = INT_MAX;
        int minn = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                nums[i] *= 2;
            }   
            pq.push(nums[i]);
            minn = min(minn,nums[i]);
        }
        while(pq.top() % 2 == 0){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-minn);
            top = top / 2;
            pq.push(top);
            minn = min(minn,top);
        }
        ans = min(ans,pq.top()-minn);
        return ans;
        // 4 2 10 20 6
    }
};
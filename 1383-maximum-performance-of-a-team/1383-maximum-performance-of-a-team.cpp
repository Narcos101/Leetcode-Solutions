class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        int mod = 1e9 + 7;
        vector<pair<int,int>>v;
        for(int i = 0; i < n;i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.first > b.first;
        });
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int res = 0;
        long long int sum = 0;
        for(int i = 0; i < n;i++){
            sum += v[i].second;
            pq.push(v[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, 1ll * v[i].first * sum);
        }
        return res % mod;
    }
};
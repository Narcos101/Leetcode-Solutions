class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;          
        }
        priority_queue<pair<int,int>>pq;
        for(auto i: mpp){
            pq.push({i.second,i.first});
        }
        string ans = "";
        while(!pq.empty()){
            for(int i = 0; i < pq.top().first; i++){
                ans += pq.top().second;    
            }
            pq.pop();
        }
        return ans;
    }
};
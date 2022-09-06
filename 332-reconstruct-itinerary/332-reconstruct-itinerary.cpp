class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mpp;
        int n = tickets.size();
        for(int i =0 ; i < n;i++){
            mpp[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string>v;
        calc("JFK",mpp,v);
        reverse(v.begin(),v.end());
        return v;
    }
    
    void calc(string s,unordered_map<string,priority_queue<string,vector<string>,greater<string>>>&mpp,vector<string>&v){
        while(mpp[s].size() != 0){
            string news = mpp[s].top();
            mpp[s].pop();
            calc(news,mpp,v);
        }
        v.push_back(s);
    }
};
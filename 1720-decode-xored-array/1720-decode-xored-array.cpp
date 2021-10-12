class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>v;
        int k = encoded.size();
        v.push_back(first);
        for(int i = 0; i < encoded.size(); i++){
            int ans = first ^ encoded[i];
            v.push_back(ans);
            first = ans;
        }
        return v;
    }
};
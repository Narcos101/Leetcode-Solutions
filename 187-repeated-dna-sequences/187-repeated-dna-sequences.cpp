class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // sliding window technique where i have to find within a given dimension
        // 
        vector<string>ans;
        map<string,int>mpp;
        if(s.size() < 10){
            return ans;
        }
        for(int i = 0; i <= s.size()-10; i++){
            mpp[s.substr(i,10)]++;
        }
        for(auto i:mpp){
            if(i.second > 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto i: nums){
            arr.push_back(to_string(i));
        }
        string res = "";
        sort(arr.begin(),arr.end(),[&](string a,string b){ return a+b > b+a ;});
        for(auto i: arr){
            res += i;
        }
        while(res.size() > 1 && res[0] == '0'){
            res.erase(0,1); 
        }
        return res;
    } 
};
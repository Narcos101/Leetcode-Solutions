class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n1 =s.size();
        int n = n1;
        unordered_map<string,int>mpp;
        for(int j = 0; j < n/2;j++){
            string ns = s.substr(0,j+1);
            int l = 0;
            int flag = true;
            for(int k = j+1;k < n;k++){
                if(l == ns.size()){
                    l = 0;
                }
                if(s[k] == ns[l]){
                    l++;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag && l == ns.size()){
                return true;
            }
        }
        return false;
    }
};
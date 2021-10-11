class Solution {
public:
char findKthBit(int n, int k) {
    string s = "0";
    while(true){
        if(k <= s.size()){
            return s[k-1];
        }
        auto ss = s;
        for(auto &ch: ss){
            if(ch == '0'){
                ch = '1';
            }
            else{
                ch = '0';
            }
        }
        reverse(ss.begin(),ss.end());
        s += '1' + ss;
    }
}

};
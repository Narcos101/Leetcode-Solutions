class Solution {
public:
    int xorOperation(int n, int start) {
        int xoro = start;
        for(int i =1; i < n;i++){
            xoro = xoro ^ (start + 2*i);
        }
        return xoro;
    }
};
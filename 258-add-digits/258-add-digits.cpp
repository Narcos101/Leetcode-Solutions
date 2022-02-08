class Solution {
public:
    int addDigits(int num) {
        int cnt = 0;
        int mod = 1000000007;
        int sum = 0;
        while(num > 9){
            while(num != 0){
                sum += num%10;
                num = num/10;
            }
            num = sum;
            sum = 0;
        }
        return num;
    }
};
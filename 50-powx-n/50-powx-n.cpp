class Solution {
public:
double myPow(double x, int a) {
double res=1;

  int  n=abs(a);
    
    while(n>0){
        if(n&1)
            res*=x;
        x*=x;
        n>>=1;
    }
    if(a==0)return 1;
    if(a>0)return res;
    else return 1/res;
   
    return res;
}
};

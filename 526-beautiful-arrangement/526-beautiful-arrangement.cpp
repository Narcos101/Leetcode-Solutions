class Solution {
public:
    int countArrangement(int n) {
        // 1 2 
        // 2 1
        int index = 0;
        int maxx = 0;
        vector<bool>isSeen(n+1,false);
        calc(n,1,maxx,isSeen);
        return maxx;
    }
    
    
    void calc(int n,int index,int&maxx,vector<bool>&isSeen){
        if(index > n){
            maxx++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(isSeen[i] == false && (i % index == 0 || index % i == 0)){
                isSeen[i] = true;
                calc(n,index+1,maxx,isSeen);
                isSeen[i] = false;
            }
        }
    }
    
};


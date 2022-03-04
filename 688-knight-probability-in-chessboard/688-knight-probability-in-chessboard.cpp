class Solution {
public:
    vector<vector<int>> matrix = {{-2,1},{-2,-1},{-1,-2},{1,2},{2,1},{-1,2},{2,-1},{1,-2}};
    double knightProbability(int n, int k, int r, int c) {
        unordered_map<string,double>mpp;
        return calc(n,k,r,c,mpp);
    }
    
    bool isValid(int n,int k,int r,int c){
        if(r < 0 || r >= n || c < 0 || c >= n){
            return false;
        }
        return true;
    }
    
    double calc(int n,int k,int r, int c,unordered_map<string,double>&mpp){
        if(!isValid(n,k,r,c)) return 0;
        if(k == 0) return 1;
        string s = to_string(r) + "found" + to_string(c) + "one" + to_string(k);
        if(mpp[s]){
            return mpp[s];
        }
        double probability = 0;
        for(int i = 0; i < matrix.size(); i++){
            probability += calc(n,k-1,r+matrix[i][0],c+matrix[i][1],mpp)/8.0;
        }
        return mpp[s] = probability;
        
    };
};
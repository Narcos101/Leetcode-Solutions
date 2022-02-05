class Solution {
public:
    bool solve (string & s, string & p, int i, int j, char prev, vector<vector<int>> & dp){
        if(dp[i][j]!=-1) return dp[i][j];
                
        if(j+1<p.length() and p[j+1]=='*')
            return dp[i][j] = solve (s, p, i, j+1, p[j], dp);
    
        if(i==s.length()){
            
            
            if(j==p.length()) return true;     
            
           
            else if(p[j]=='*')                 
                return dp[i][j] = solve(s, p, i, j+1, '*', dp);
        
            
            else return false;
        }
        
        
        else if(j==p.length()) return false;
        
        
        
        
        if(p[j]=='.' or p[j]==s[i])
            return dp[i][j] = solve(s, p, i+1, j+1, p[j], dp);
        
        
        else if(p[j]=='*'){
            
            
            if(prev=='.' or prev==s[i]){
                
                bool res = solve (s, p, i+1, j, prev, dp);
                
                
                bool res2 = solve (s, p, i+1, j+1, '*', dp);
                
                
                bool res3 = solve (s, p, i, j+1, '*', dp);
                
                return dp[i][j] = res or res2 or res3;
            }
                
            
            else{    
                bool res = solve (s, p, i, j+1, '*', dp);
                return dp[i][j] = res;
            }
        }
        

        return false;
    }
    
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp (s.length()+1, vector<int> (p.length()+1, -1));
        return solve (s, p, 0, 0, ' ', dp);
    }
};
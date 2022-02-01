class Solution {

public:
    
    int t[2001][2001];
    bool ispal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s,int i,int j)
    {
        //base-->
        if(i>=j || ispal(s,i,j))
        {
            return t[i][j]=0;
        }
        
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int minans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispal(s,i,k))//only when left partition is palindrome we check for right part
            {
                int temp=solve(s,k+1,j)+1;
                minans=min(minans,temp);
                t[i][j]=minans;
            }
           
        }
        return minans;
    }

    int minCut(string s)
    {
        int n=s.length();
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
        
        
    }
};
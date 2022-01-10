// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPalindrome(int start,int end, string& s){
        
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }


    int calc(int i, int j, string& str,vector<vector<int>>&dp){
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        if(i >= j || isPalindrome(i,j,str)){
            return 0;
        }
        for(int k = i; k < j; k++){
            dp[i][j] = min(dp[i][j],(calc(i, k, str,dp) + calc(k+1,j,str,dp) + 1));
        }
        
        return dp[i][j];        
        
    }




    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size()-1;
        int N = str.size();
        vector<vector<int>>dp(N,vector<int>(N,INT_MAX));
        return calc(i, j, str,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
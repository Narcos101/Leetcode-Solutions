// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s1) { 
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        int L[n+1][n+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                    continue;
                }
                
                if(s1[i-1] == s2[j-1]){
                    L[i][j] = 1 + L[i-1][j-1];
                }
                else{
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
                }
            }
        }
        return n-L[n][n];
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}  // } Driver Code Ends
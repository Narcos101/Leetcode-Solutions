// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string X, string Y) 
	{ 
	    int n = X.size();
	    int m = Y.size();
	    int L[n+1][m+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                    continue;
                }
                
                if(X[i-1] == Y[j-1]){
                    L[i][j] = 1 + L[i-1][j-1];
                }
                else{
                    L[i][j] = max(L[i-1][j],L[i][j-1]);
                }
            }
        }
        return (n+m-2*L[n][m]);
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
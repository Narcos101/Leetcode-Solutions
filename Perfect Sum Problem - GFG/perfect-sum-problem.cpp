// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long count=0;
	int dp[1001][1001];
	int ok(int arr[], int n, int sum)
	{
	    if(sum==0)return 1;
        if(n==0)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];
        else if(sum>=arr[n-1])
        {
            return count=dp[n][sum]=(((ok(arr,n-1,sum-arr[n-1])%1000000007)+(ok(arr,n-1,sum)%1000000007))%1000000007);
        }
        else return dp[n][sum]=(ok(arr,n-1,sum)%1000000007);
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    memset(dp,-1,sizeof(dp));
        return ok(arr,n,sum);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
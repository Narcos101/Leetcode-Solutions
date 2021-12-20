// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums1[])
    {
        int nums2[n];
        for(int i = 0; i < n; i++){
            nums2[i] = nums1[i];
        }
        sort(nums2,nums2 + n);
        int dp[n+1][n+1];
        for(int  i = n-1; i > 0; i--){
            if(nums2[i] == nums2[i-1]){
                nums2[i] = INT_MAX;
            }
        }
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if((nums1[i-1] == nums2[j-1]) && (nums2[j-1] != INT_MAX)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
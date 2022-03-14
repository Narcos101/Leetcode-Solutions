// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void calc(vector<vector<int>> &m, int n,vector<string>&ans,vector<vector<int>>&vis,string s,int row, int col,vector<vector<int>>&dir){
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        string temp = "DRUL";
        int i = row;
        int j = col;
        for(int k = 0; k < dir.size(); k++){
            i = row + dir[k][0];
            j = col + dir[k][1];
            if(i < n && i >= 0 && j < n && j >= 0 && vis[i][j] == 0 && m[i][j] == 1){
                vis[row][col] = 1;
                calc(m,n,ans,vis,s + temp[k],i,j,dir);
                vis[row][col] = 0;
            }
        }
        
    }
    

    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<string>ans;
       vector<vector<int>>vis(n,vector<int>(n,0));
       vector<vector<int>>dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
       if(m[0][0] == 0){
           return ans;
       }
       calc(m,n,ans,vis,"",0,0,dir);
       return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
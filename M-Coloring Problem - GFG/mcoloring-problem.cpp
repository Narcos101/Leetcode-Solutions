// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.



bool isSafe(bool graph[101][101],vector<int>&color,int n, int colour,int index){
    
    for(int i = 0; i < n; i++){
        if(index != i && graph[i][index] == 1 && color[i] == colour){
            return false;
        }
    }
    return true;
}






bool calc(bool graph[101][101], vector<int>&color, int m, int V,int index){
    if(index == V){
        return true;
    }
    for(int i = 1; i <= m; i++){
        if(isSafe(graph,color,V,i,index)){
            color[index] = i;
            if(calc(graph,color,m,V,index+1)){
                return true;
            };
            color[index] = 0;
        }
    }
    return false;
}



bool graphColoring(bool graph[101][101], int m, int V)
{
    // 0 1 2 3
    vector<int>color(V,0);
    return calc(graph,color,m,V,0);
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
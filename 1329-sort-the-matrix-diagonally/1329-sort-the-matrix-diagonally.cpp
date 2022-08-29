class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i = 0;i < m;i++){
            int k = 0;
            int j = i;
            vector<int>v;
            while(k < n && j < m){
                v.push_back(mat[k][j]);
                k++;
                j++;
            }  
            sort(v.begin(),v.end());
            k = 0;
            j = i;
            int l = 0;
            while(k < n && j < m){
                ans[k][j] = v[l];
                k++;
                j++;
                l++;
            }
        }
        for(int i = 1;i < n;i++){
            int k = i;
            int j = 0;
            vector<int>v;
            while(k < n && j < m){
                v.push_back(mat[k][j]);
                k++;
                j++;
            }  
            sort(v.begin(),v.end());
            k = i;
            j = 0;
            int l = 0;
            while(k < n && j < m){
                ans[k][j] = v[l];
                k++;
                j++;
                l++;
            }
        }
        return ans;
    }
};
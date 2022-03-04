class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>newTriangle = triangle;
        int n = triangle.size();
        if(n == 1){
            return triangle[0][0];
        }
        if(n == 2){
            return min(triangle[1][0] + triangle[0][0], triangle[1][1] + triangle[0][0]);
        }
        
        for(int i = n-2; i >= 0;i--){
            for(int j = 0; j < triangle[i].size(); j++){
                newTriangle[i][j] += min(newTriangle[i+1][j],newTriangle[i+1][j+1]);
            }
        }
        return newTriangle[0][0];
    }
};
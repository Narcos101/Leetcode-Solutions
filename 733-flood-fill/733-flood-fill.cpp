class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        calc(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
    
    void calc(vector<vector<int>>& image,int i, int j, int newColor,int color){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != color || image[i][j] == newColor){
            return;
        }
        image[i][j] = newColor;
        calc(image,i+1,j,newColor,color);
        calc(image,i-1,j,newColor,color);
        calc(image,i,j+1,newColor,color);
        calc(image,i,j-1,newColor,color);
    }
};
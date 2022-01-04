class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxx = 0;
        while(left < right){
            if(height[left] >= height[right]){
                maxx = max(maxx,(right-left) * height[right]);
                right--;
            }
            else{
                maxx = max(maxx,(right-left) * height[left]);
                left++;
            }
        }
        return maxx;
    }
};
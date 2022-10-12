class Solution {
public:
    
    int area(int a,int b,int c){
        int s = (a + b + c)/2;
        int areas = sqrt(s * (s-a) * (s-b) * (s-c));
        cout << s << " " << areas << endl;
        return areas;
    }
    
    
    
    
    
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n <= 2){
            return 0;
        }
        int maxx = 0;
        for(int i = 0; i < n-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a + b > c && a + c > b && b + c > a){
                int val = a + b + c;
                maxx = max(maxx,val);
            }
        }
        return maxx;
    }
};
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = pow(10,9);
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            if(possible(mid,h,piles)){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
    }
    
    
    bool possible(int speed, int h, vector<int>& piles){
        int time = 0;
        for(auto p:piles){
            time += (p / speed);
            if(p % speed){
                time += 1;
            }
        }
        return time <= h;
    }
    
};
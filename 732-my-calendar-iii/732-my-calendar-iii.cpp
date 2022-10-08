class MyCalendarThree {
public:
    map<int,int>mpp;
    int ans = 1;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int sum = 0;
        for(auto i : mpp){
            sum += i.second;
            ans = max(ans,sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
class MyCalendar {
public:
    // priority queue
    // 10-20
    // 15-25
    // 20-30
    unordered_map<int,int>mpp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto i: mpp){
            if(start < i.second && end > i.first){
               return false;
            }
        }   
        mpp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
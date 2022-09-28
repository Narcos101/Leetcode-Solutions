class MyCircularQueue {
public:
    int size = 0;
    int i = 0;
    int j = 0;
    int lk = 0;
    vector<int>v;
    MyCircularQueue(int k) {
        v.resize(k,-1);
        lk = k;
    }
    
    bool enQueue(int value) {
        // for(int i = 0; i < lk;i++){
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        if(size == lk){
            return false;
        }
        else{
            v[j] = value;
            size++;
            j = (j + 1) % lk;
            return true;
        }
    }
    
    bool deQueue() {
        if(size == 0){
            return false;
        }
        else{
            v[i] = -1;
            size--;
            i = (i + 1) % lk;
            return true;
        }
    }
    
    int Front() {
        return v[i];    
    }
    
    int Rear() {
        if(j-1 < 0){
            return v[lk-1];
        }
        else{
            return v[j-1];
        }
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == lk;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
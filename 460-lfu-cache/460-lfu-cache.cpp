struct Node{
    int key;
    int value;
    int cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};


struct List{
    Node *head;
    Node *tail;
    int size;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addfront(Node *newnode){
        Node *temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        newnode->prev = head;
        temp->prev = newnode;
        size++;
    }
    void removeNode(Node *delnode){
        Node *delnext = delnode->next;
        Node *delprev = delnode->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
        size--;
    }
};


class LFUCache {
public:
    map<int,Node*>keyNodemap;
    map<int,List*>freqListMap;
    int currsize;
    int minfreq;
    int maxcachesize;
    
    LFUCache(int capacity) {
        maxcachesize = capacity;
        minfreq = 0;
        currsize = 0;
    }
    
    void updateFreqList(Node *node){
        keyNodemap.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(freqListMap[node->cnt]->size == 0 && node->cnt == minfreq){
            minfreq++;
        }
        List *nexthigherlist = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nexthigherlist = freqListMap[node->cnt+1];        
        }
        node->cnt += 1;
        nexthigherlist->addfront(node);
        freqListMap[node->cnt] = nexthigherlist;
        keyNodemap[node->key] = node;
    }
    
    
    
    int get(int key) {
        if(keyNodemap.find(key) != keyNodemap.end()){
            Node *node = keyNodemap[key];
            int res = node->value;
            updateFreqList(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxcachesize == 0){
            return;
        }    
        if(keyNodemap.find(key) != keyNodemap.end()){
            Node *resnode = keyNodemap[key];
            resnode->value = value;
            updateFreqList(resnode);
        }
        else{
            if(currsize == maxcachesize){
                List *list = freqListMap[minfreq];
                keyNodemap.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq = 1;
            List *newlist = new List();
            if(freqListMap.find(minfreq) != freqListMap.end()){
                newlist = freqListMap[minfreq];
            }
            Node *node = new Node(key,value);
            newlist->addfront(node);
            keyNodemap[key] = node;
            freqListMap[minfreq] = newlist;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
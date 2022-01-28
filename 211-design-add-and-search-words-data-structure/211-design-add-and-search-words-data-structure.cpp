struct Node{
    Node *links[26];
    bool flag = 0;
    // contains,put,get,isend,putend
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void putKey(char ch, Node *node){
        links[ch-'a'] = node;
    }
    Node* getKey(char ch){
        return links[ch-'a'];
    }
    void putEnd(){
        flag = 1;
    }
    bool isEnd(){
        return flag;
    }
};


class WordDictionary {
    Node *root = new Node();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node *node = root;
        for(int i =0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i],new Node());
            }
            node = node->getKey(word[i]);
        }
        node->putEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        return search1(word,0,node);
    }
    bool search1(string word, int index,Node *root){
        Node *node = root;
        for(int i = index; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26;j++){
                    if(node->links[j] == NULL){
                        continue;
                    }
                    word[i] = j+'a';
                    if(search1(word,i+1,node->getKey(word[i]))){
                        return true;
                    }
                    word[i]='.';
                }
                return false;
            }
            else{
                if(!node->containsKey(word[i])){
                    return false;
                }
                node = node->getKey(word[i]);
            }
        }
        if(node->isEnd()){
            return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
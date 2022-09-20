
struct Trie{
    Trie* ch[26] = {NULL}; // pointer points to the next array of characters
    int precnt = 0;
    bool isEnd = false;
    void putKey(char key,Trie *newNode){
        ch[key-'a'] = newNode;
    }
    Trie* getKey(char key){
        return ch[key-'a'];
    }
    bool hasKey(char key){
        return ch[key-'a'] != NULL;
    }
    void setIsEnd(){
        isEnd = true;
    }
    bool isend(){
        return isEnd;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        int n = words.size();
        Trie*root = new Trie();
        for(int i =0; i < n;i++){
            Trie*node = root;
            for(int j = 0; j < words[i].size();j++){
                char ch = words[i][j];
                if(!node->hasKey(ch)){
                    node->putKey(ch,new Trie());
                }
                node = node->getKey(ch);
                node->precnt++;
            }
            node->setIsEnd();
        }
        for(int i = 0; i < words.size();i++){
            int cnt = 0;
            Trie *node = root;
            for(int j =0; j < words[i].size();j++){
                char ch = words[i][j];
                node = node->getKey(ch);
                cnt += node->precnt;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
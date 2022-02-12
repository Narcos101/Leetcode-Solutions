class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        bool isPresent = false;
        unordered_set<string>myset;
        for(int i = 0;i < words.size();i++){
            if(words[i] == end){
                isPresent = true;
            }
            myset.insert(words[i]);
        }       
        if(!isPresent) return false;
        queue<string>q;
        q.push(begin);
        int depth = 0;
        while(!q.empty()){
            depth += 1;
            int size = q.size();
            for(int i = 0; i < size;i++){
                string curr = q.front();
                q.pop();
                for(int i = 0; i < curr.size(); i++){
                    string temp = curr;
                    for(char c='a'; c <='z';c++){
                        temp[i] = c;
                        if(temp.compare(curr) == 0){
                            continue;
                        }
                        if(temp.compare(end) == 0){
                            return depth+1;                    
                        }
                        if(myset.find(temp) != myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }            
        }
        return 0;
    }
};
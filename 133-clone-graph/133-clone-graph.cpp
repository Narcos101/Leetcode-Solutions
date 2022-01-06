/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        if(mpp.find(node) == mpp.end()){
            mpp[node] = new Node(node->val, {});
            for(auto nope: node->neighbors){
                mpp[node]->neighbors.push_back(cloneGraph(nope));
            }
        }
        return mpp[node];
    }
    private:
        unordered_map<Node*,Node*>mpp;
};
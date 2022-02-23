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
        if(node == NULL){
            return NULL;
        }
        Node *root = new Node(node->val,{});
        map<Node*,Node*>mpp;
        mpp[node] = root;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            for(auto i: node->neighbors){
                if(mpp.find(i) == mpp.end()){
                    mpp[i] = new Node(i->val,{});
                    q.push(i);
                }
                mpp[node]->neighbors.push_back(mpp[i]);
            }
        }
        return root;
    }
};
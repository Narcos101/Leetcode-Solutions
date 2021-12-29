/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*>q;
        q.push(root);
        Node *prev, *next;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                prev = q.front();
                q.pop();
                if(i != n-1) next = q.front();
                else next = NULL;
                prev->next = next;
                if(prev->left != NULL){
                    q.push(prev->left);
                }
                if(prev->right != NULL){
                    q.push(prev->right);
                }
                
            }
        }
        return root;
    }
};
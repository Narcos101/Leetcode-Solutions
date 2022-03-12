/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // traverse throught the list, if the node doesn't exist make one 
        // As the values are not unique we cannot store the value of a particular node as an identifier
        // In this case we will store the address of the original node and store the clone nodes address
        // to check whether the copy of the original node has been created or not 
        
        map<Node*,Node*>mpp;
        Node* head2 = head;
        while(head != NULL){
            Node *node = new Node(head->val);
            mpp[head] = node;
            head = head->next;
        }
        head = head2;
        while(head2 != NULL){
            mpp[head2]->next = mpp[head2->next];
            mpp[head2]->random = mpp[head2->random];
            head2 = head2->next;
        }
        return mpp[head];
    }
};
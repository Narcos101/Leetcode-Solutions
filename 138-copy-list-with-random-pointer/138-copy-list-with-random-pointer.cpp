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
        map<Node*,Node*>mpp;
        Node *head2 = head;
        while(head2 != NULL){
            mpp[head2] = new Node(head2->val);
            head2 = head2->next;
        }
        head2 = head;
        Node *head3 = mpp[head2];
        while(head2!=NULL){
            mpp[head2]->next = mpp[head2->next];
            mpp[head2]->random = mpp[head2->random];
            head2 = head2->next;
        }
        
        mpp.clear();
        return head3;
    }
};
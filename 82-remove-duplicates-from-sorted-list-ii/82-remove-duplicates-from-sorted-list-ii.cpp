class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // store all the values of the nodes which are duplicate in a hashmap and on the next iteration just remove them by                 iterating
        // O(2n) and S.C O(n)
        //we are naturally aiming at a solution with O(n) and O(n);
        ListNode *curr = head;
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *prev = temp;
        while(curr != NULL && curr->next != NULL){
            if(curr->val != curr->next->val){
                prev = curr;
                curr = curr->next;
            }
            else{
                while(curr->next != NULL && curr->val == curr->next->val){
                    curr = curr->next;
                }
                curr = curr->next;
            }
            prev->next = curr;
        }
        return temp->next;
    }
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next_pointer = dummyNode->next;
            ListNode* prev_pointer = dummyNode;
            while(next_pointer != NULL){
                if(curr->val < next_pointer->val){
                    break;
                }
                next_pointer = next_pointer->next;
                prev_pointer = prev_pointer->next;
            }
            ListNode* temp = curr->next;
            prev_pointer->next = curr;
            curr->next = next_pointer;
            curr = temp;
        }
        return dummyNode->next;
    }
};

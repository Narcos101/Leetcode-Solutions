/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        int flag = 0;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                flag = 1;
                break;
            }
        }
        if(flag){
            ListNode *temp = head;
            while(true){
                if(temp == slow){
                    return temp;
                }
                else{
                    temp = temp->next;
                    slow = slow->next;
                }
            }        
        }
        return NULL;
    }
};
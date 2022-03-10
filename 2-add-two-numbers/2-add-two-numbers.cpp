/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = NULL;
        ListNode *prev = dummyNode;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val;
            if(carry){
                sum += carry;
                carry = 0;
            }
            if(sum >= 10){
                carry = sum / 10;
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            else{
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        int sum = 0;
        while(l1 != NULL){
            sum = l1->val;
            if(carry){
                sum += carry;
                carry = 0;
            }
            if(sum >= 10){
                carry = sum / 10;
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            else{
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            l1 = l1->next;
        }
        while(l2 != NULL){
            sum = l2->val;
            if(carry){
                sum += carry;
                carry = 0;
            }
            if(sum >= 10){
                carry = sum / 10;
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            else{
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            l2 = l2->next;
        }
        if(carry){
            prev->next = new ListNode(carry);
            prev = prev->next;
        }
        return dummyNode->next;
    }
};
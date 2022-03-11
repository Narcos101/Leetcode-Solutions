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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *temp = head;
        int size = 0;
        while(temp->next != NULL){
            size++;
            temp = temp->next;
        }
        size++;
        k = k % size;
        if(k == size || k == 0){
            return head;
        }
        int num = size-k-1;
        ListNode *temp1 = head;
        while(num != 0){
            temp1 = temp1->next;
            num--;
        }
        temp->next = head;
        head = temp1->next;
        temp1->next = NULL;
        return head;
    }
};
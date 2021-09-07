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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *temp = head;
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode *left_side = sortList(head);
        ListNode *right_side = sortList(slow);
        return merge(left_side,right_side);
    }
    
    private:
        ListNode *merge(ListNode *l1,ListNode *l2){
            ListNode *sorted_temp = new ListNode(0);      
            ListNode *current_node = sorted_temp;
            while(l1 != NULL && l2 != NULL){
                if(l1->val < l2->val){
                    current_node->next = l1;
                    l1 = l1->next;
                }
                else{
                    current_node->next = l2;
                    l2 = l2->next;
                }
                current_node = current_node->next; 
            }
            if(l1 != NULL){
                current_node->next = l1;   
            }
            
            if(l2 != NULL){
               current_node->next = l2; 
            }
            return sorted_temp->next;
        }
};
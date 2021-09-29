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
    int getSize(ListNode *head){
        int counter = 0;
        while(head){
            counter++;
            head = head->next;
        }
        return counter;
    }
    
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalsize = getSize(head);
        vector<ListNode*>res;
        int size = totalsize/k;
        int extra = totalsize%k;
        for(int i =0;i < k; i++){
            ListNode *tmp = new ListNode(0,head);
            ListNode *tempHead = tmp;
            for(int j = 0; j < size; j++){
                tmp = tmp->next;
            }
            if(extra){
                tmp = tmp->next;
                extra--;
            }
            head = tmp->next;
            tmp->next = NULL;
            
            res.push_back(tempHead->next);
        }
        return res;
    }
};
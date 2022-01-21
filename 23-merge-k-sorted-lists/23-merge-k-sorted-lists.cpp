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
    
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode *temp = NULL;
        if(a->val <= b->val){
            temp = a;
            temp->next = merge(a->next,b);
            return temp;
        }
        else{
            temp = b;
            temp->next = merge(a,b->next);
            return temp;
        }
    }
    
    
    
    
    ListNode* mergeLists(vector<ListNode*>&lists,int k){
        while(k != 0){
            int i = 0;
            int j = k;
            while(i < j){
                lists[i] = merge(lists[i],lists[j]);
                i++;
                j--;
                if(i >= j){
                    k = j;
                }
            }
        }
        return lists[0];
    }
    
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;    
        }
        if(lists.size() == 1){
            return lists[0];
        }
        int k = lists.size()-1;
        ListNode*ans = mergeLists(lists,k);
        return ans;
    }
};
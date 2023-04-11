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
    ListNode *detectCycle(ListNode *slow,ListNode *head) {
        if(slow==head) return slow;
        while(true){
            head=head->next;
            slow=slow->next;
            if(slow==head) return slow;
            
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
         ListNode* temp = head;
        if(!temp || !temp->next) return NULL;
        ListNode* slow = temp;
        ListNode* fast = temp;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return detectCycle(head,fast);
        }
        return NULL;
    }
};
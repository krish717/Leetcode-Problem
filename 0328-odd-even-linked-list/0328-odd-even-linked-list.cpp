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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        if(temp==NULL) return NULL;
        ListNode* odd = new ListNode(-909);
        int odds = 1;
        int evens=1;
        ListNode* oddTail = new ListNode(-909);
        ListNode* even = new ListNode(-979);
        ListNode* evenTail = new ListNode(-979);
        int i = 1;
        while(temp!=NULL){
            if(i%2!=0){
                if(odds==1){
                    odd->next = temp;
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                    odds=0;
                }else{
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
                
            }else{
                if(evens==1){
                    even->next = temp;
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                    evens=0;
                }else{
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            temp=temp->next;
           i++;
        }
        oddTail->next = even->next;
        evenTail->next = NULL;
        return odd->next;
    }
};
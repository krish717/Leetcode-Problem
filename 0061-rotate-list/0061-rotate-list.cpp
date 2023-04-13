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
        if(!head || k==0) return head;
        ListNode* tail = head;
        int count=1;
        while(tail->next!=NULL){
            count++;
            tail = tail->next;
        }
        tail->next = head;
        k=k%count;
        k=count-k;
        while(k!=0){
            tail=tail->next;
            k--;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
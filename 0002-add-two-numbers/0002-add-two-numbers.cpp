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
    void addition(ListNode* &head, ListNode* &tail,int digit){
        ListNode* newNode = new ListNode(digit);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    ListNode* addtoNumber(ListNode* l1, ListNode* l2){
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int val1 = 0;
            if(l1!=NULL) val1 = l1->val;
            int val2 = 0;
            if(l2!=NULL) val2 = l2->val;
            int add = val1 + val2 + carry;
            int digit = add%10;
            addition(head,tail,digit);
            carry = add/10;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;  
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        return addtoNumber(l1,l2);
    }
};
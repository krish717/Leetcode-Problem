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
    ListNode* reverse(ListNode* head){
        
        if(head==NULL || head->next==NULL) return head;
        ListNode* ans = reverse(head->next);
         head->next->next = head;
        head->next=NULL;
        return ans;
    }
    ListNode* middle(ListNode* head){
       ListNode* slow = head;
       ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        if(temp==NULL || temp->next==NULL) return true;
        ListNode* mid = middle(head);
        ListNode* secondlist = mid->next;
        mid->next = NULL;
        
        
        ListNode* rev = reverse(secondlist);
        while(head!=NULL && rev!=NULL){
            if((head->val)!=(rev->val)) return false;
            head=head->next;
            rev=rev->next;
        }
        return true;
    }
};
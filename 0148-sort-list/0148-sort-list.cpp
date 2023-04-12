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
    ListNode *MiddleofLL(ListNode *head)
{
      if(head==NULL || head->next==NULL)
        return head;
      ListNode *slow = head;
      ListNode *fast = head->next;
      while(fast!=NULL && fast->next!=NULL)
      {
            slow=slow->next;
            fast=fast->next->next;
      }
      return slow;
}
    ListNode *mergetwoLinkedList(ListNode *head1, ListNode *head2)
{
      if(!head1){ return head2; }
      if(!head2){ return head1; }
      ListNode *temp1 = head1;
      ListNode *temp2 = head2;
      ListNode *headmain = NULL;
      ListNode *tailmain = NULL;
      while(temp1!=NULL && temp2!=NULL){
            if(headmain==NULL){
                  if(temp1->val<temp2->val)
                  {
                        headmain = temp1;
                        tailmain = temp1;
                        temp1=temp1->next;
                  }else{
                         headmain = temp2;
                        tailmain = temp2;
                        temp2=temp2->next;
                  }
            }
                  else
                  {
                       if(temp1->val<temp2->val)
                       {
                            tailmain->next = temp1;
                            tailmain = tailmain->next;
                            temp1=temp1->next;
                       }else{
                             tailmain->next = temp2;
                            tailmain = tailmain->next;
                            temp2=temp2->next;
                       }
                       
                  }
            }
           if(temp2 != NULL) {
        tailmain->next = temp2;
    }
    if(temp1 != NULL) {
        tailmain->next = temp1;
    }
      return headmain;
      }
      
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
      {
            return head;
      }
      ListNode *mid = MiddleofLL(head);
      ListNode *head1 = head;
      ListNode *head2 = mid->next;
      mid->next=NULL;
     
      ListNode *h1 = sortList(head1);
      ListNode *h2 = sortList(head2);
      
     ListNode *ans  = mergetwoLinkedList(h1,h2);
      
      return ans;
    }
};
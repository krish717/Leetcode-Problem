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
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL) return head;
        //     ListNode* curr = head;
        //     ListNode* prev = NULL;
        //     ListNode* next = NULL;
        //     while(curr!=NULL){
        //             next = curr->next;
        //             curr->next = prev;
        //             prev = curr;
        //             curr = next;
        //     }
        //     return prev;
            ListNode *temp = head;
            if(head==NULL || head->next==NULL) return head;
            ListNode *ans = reverseList(head->next);
            
            ListNode *temp2 = ans;
            while(temp2->next!=NULL) temp2 = temp2->next;
            temp2->next = temp;
            temp->next = NULL;
            return ans;
            
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode *prev = dummyNode;
            if(head==NULL) return head;
            while(prev!=NULL && prev->next){
                    if(prev->next->val == val){
                            prev->next = prev->next->next;
                    }else{
                            prev= prev->next;
                    }
            }
            return dummyNode->next;
    }
};
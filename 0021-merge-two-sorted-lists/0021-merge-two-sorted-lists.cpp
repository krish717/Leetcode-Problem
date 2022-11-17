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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode *node2 = new ListNode(-1);
        //     ListNode *node1 = node2;
        //  if(list1==NULL) return list2;
        //  if(list2==NULL) return list1;   
        //     while(list1!=NULL && list2!=NULL){
        //             if(list1->val < list2->val){
        //                     node1->next = list1;
        //                     node1 = node1->next;
        //                     list1 = list1->next;
        //             }else{
        //                    node1->next = list2;
        //                    node1 = node1->next;
        //                    list2 = list2->next; 
        //             }
        //     }
        //     if(list1!=NULL) node1->next = list1;
        //     if(list2!=NULL) node1->next = list2;
        //     return node2->next;
            
             if(list1==NULL) return list2;
             if(list2==NULL) return list1; 
            
             ListNode *res;
             if(list1->val < list2->val){
                     res = list1;
                    res->next =  mergeTwoLists(list1->next, list2);
             }else{
                     res = list2;
                     res->next =   mergeTwoLists(list1, list2->next);
             }
            
            return res;
    }
};
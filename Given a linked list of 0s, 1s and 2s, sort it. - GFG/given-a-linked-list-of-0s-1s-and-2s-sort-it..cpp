//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node *MiddleofLL(Node *head)
{
      if(head==NULL || head->next==NULL)
        return head;
      Node *slow = head;
      Node *fast = head->next;
      while(fast!=NULL && fast->next!=NULL)
      {
            slow=slow->next;
            fast=fast->next->next;
      }
      return slow;
}
Node *mergetwoLinkedList(Node *head1, Node *head2)
{
      if(!head1){ return head2; }
      if(!head2){ return head1; }
      Node *temp1 = head1;
      Node *temp2 = head2;
      Node* newNode = new Node(-11);
      Node *headmain = newNode;
      Node *tailmain = NULL;
      while(temp1!=NULL && temp2!=NULL){
            
                  if(temp1->data<temp2->data)
                  {
                        headmain->next = temp1;
                        headmain = headmain->next;
                        temp1=temp1->next;
                  }else{
                         headmain->next = temp2;
                        headmain = headmain->next;
                        temp2=temp2->next;
                  }
            
                 
            }
           if(temp2 != NULL) {
        headmain->next = temp2;
         headmain = headmain->next;
    }
    if(temp1 != NULL) {
       headmain->next = temp1;
         headmain = headmain->next;
    }
      return newNode->next;
      }
    Node* segregate(Node *head) {
        
         if(head==NULL || head->next==NULL)
      {
            return head;
      }
      Node *mid = MiddleofLL(head);
      Node *head1 = head;
      Node *head2 = mid->next;
      mid->next=NULL;
     
      Node *h1 = segregate(head1);
      Node *h2 = segregate(head2);
      
     Node *ans  = mergetwoLinkedList(h1,h2);
      
      return ans;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
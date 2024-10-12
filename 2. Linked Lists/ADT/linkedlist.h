/* Data Declaration Start */
struct ListNode {
    int data;
    struct ListNode *next;
};
typedef struct ListNode LNode;
/* Data Declaration End */
/* Function Declaration Start */
LNode *createList(int data);
void   insertAtEnd(LNode **head, int data);
void   insertAtFront(LNode **head, int data);
/*
Notes:
If the linked list contains even number of elements, 
N elements, I will insert the node after the N/2th position. 
eg: 1 => 2 => 3 => 4, Insert Node with Value 5 in the middle, the list will insert the node as below:-
1 => 2 => 5 => 3 => 4
If the value of N is odd, then we will insert just after the middle node, ceil(N/2)
eg: 1 => 2 => 3, Insert Node with Value 4
1 => 2 => 4 => 3
*/
void   insertAtMiddle(LNode **head, int data);
void   printList(LNode *head);
void   deleteFirstNode(LNode **head);
void   deleteLastNode(LNode **head);
void   deleteLinkedList(LNode **head);
/* Function Declaration End */
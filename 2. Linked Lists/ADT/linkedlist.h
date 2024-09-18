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
void   printList(LNode *head);
/* Function Declaration End */
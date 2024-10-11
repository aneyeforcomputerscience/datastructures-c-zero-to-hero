#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
LNode *createList(int data) {
    //Declare a new node
    LNode *newNode = (void *)0;
    //Allocate memory to the new node.
    newNode = (LNode *)malloc(sizeof(LNode));
    //Check if malloc is successful.
    if (newNode == (void *)0){
        return (void *)0;
    } else {
        //Populate the field data of the newNode.
        newNode->data = data;
        //Populate the next pointer to point to NULL.
        newNode->next = (void *)0;
        //Return the newNode.
        return newNode;
    }
}

static LNode *createNode(int data) {
    //Allocating a new node
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    //Populating the data field
    newNode->data  = data;
    //Populating the next field to NULL
    newNode->next  = (void *)0;
    //Return the new node
    return newNode;
}

//NULL => create A New List with the data.
//otherwise => we have to go the end of the list. 
//insert the new node.
//1=>2=>3=>4=>NULL
void insertAtEnd(LNode **head, int data) {
    if (*head == (void *)0) {
        //createList was not called. So, we create a new list here.
        printf("Warning: Create List was not called.\n");
        printf("Creating a new list.\n");
        *head = createList(data);
    } else {
        //Set the current pointer to content of head.
        LNode *current = *head;
        //Traverse while we reach the last node
        while (current->next != (void *)0) {
            //Advance the pointer to the next node.
            current = current->next;
        }
        //Create a new temporary node.
        LNode *temp = createNode(data);
        //Assign the next field of last node to temp.
        current->next = temp;
        //1=>2=>3=>4=>5=>(void *)0
        temp->next    = (void *)0;
    }
}

void insertAtFront(LNode **head, int data) {
    if (*head == (void *)0){
        //createList was not called. So, we create a new list here.
        printf("Warning: Create List was not called.\n");
        printf("Creating a new list.\n");
        *head = createList(data);
    } else {
        //Create a new temporary node with the data.
        LNode *temp = createNode(data);
        //1 : Insert Node with Data Value 3
        //a) Assign the next field of temp to head
        temp->next  = *head;
        //b) The new head is assigned to temp.
        *head       = temp;
    }
}

void insertAtMiddle(LNode **head, int data) {
    if (*head == (void *)0){
        //createList was not called. So, we will create a new list.
        printf("Warning: createList was not called.\n");
        printf("Creating a new list.\n");
        *head = createList(data);
    } else {
        //1 => 2 => 3 => 4 => 5
        //Maintain two pointers. 
        //fastPointer advances by 2 positions.
        //slowPointer advances by 1 position.
        //10 => 20 => 30 => 40 => 50 => (void *) 0
        LNode *slowPointer = *head;
        LNode *fastPointer = *head;
        while(slowPointer             != (void *) 0 && 
              fastPointer             != (void *) 0 && 
              fastPointer->next       != (void *) 0 && 
              fastPointer->next->next != (void *) 0) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        LNode *temp = createNode(data);
        //1 => 2 => 3 => 4 => 5 => (void *)0
        //6 => 4 => 5 => (void *) 0
        temp->next  = slowPointer->next;
        //1 => 2 => 3 => 6 => 4 => 5 => (void *)0
        slowPointer->next = temp;
    }
}

void printList(LNode *head) {
    //If the list is empty, I want a meaningful message that informs
    //that the list is empty.
    LNode *current = head;
    if (current == (void *)0){
        //Print message if list empty. 
        printf("List is empty.\n");
    } else {
        //Current is not NULL.
        while(current!=(void *)0){
            //Print the Data
            printf("%d ",current->data);
            //Go to the next node.
            current = current->next;
        }
    }
    printf("\n");
}

static void deleteNode(LNode *node){
    free(node); //To avoid memory leaks.
    node = (void *)0; //To avoid dangling pointer.
}

void deleteFirstNode(LNode **head){
    if(head == (void *)0 || *head == (void *)0){
        printf("The Linked List is not populated.\n");
        return;
    } else {
        //1=>2=>3=>4
        LNode *temp = *head;
        *head = (*head)->next;
        deleteNode(temp);
    }
}

int main() {
    LNode *head = createList(10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printList(head); //10 20 30 40 50
    deleteFirstNode(&head);
    printList(head); //20 30 40 50
}
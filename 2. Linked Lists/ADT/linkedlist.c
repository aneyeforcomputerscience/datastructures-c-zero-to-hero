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
int main() {
    LNode *head = createList(10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Data at 1st node = %d\n",head->data);
    printf("Data at 2nd node = %d\n",head->next->data);
    printf("Data at 3rd node = %d\n",head->next->next->data);
    printf("Data at 4th node = %d\n",head->next->next->next->data);
}
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
int main() {
    LNode *head = createList(1);
    printf("Data = %d \n", head->data);
}
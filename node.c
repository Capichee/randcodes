#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

void insertAtBeginning(Node ** head, int newData){
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = * head;
    *head = newNode;
}

void insereAtEnd(Node ** head, int newData){
    Node * newNode = (Node*)malloc(sizeof(Node));
    Node * last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
}

void insertInOrder(Node ** head, int newData){
    Node * newNode = (Node*)malloc(sizeof(Node));
    Node * current;

    newNode->data = newData;
    newNode->next = NULL;

    if(*head == NULL || (*head)->data >= newData){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    else{
        current = *head;
        while(current->next != NULL && current->next->data < newData){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return;
    }

}

void printList(Node * node){
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteNode(Node**head, int key){
    Node * temp = *head;
    Node * prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main(){

    Node * head = NULL;

    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertInOrder(&head, 25);
    printList(head);

    return 0;

}